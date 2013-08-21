class mini_move : pubic BASE_MOVE<mini>
{
    public :

    mini_move ( /* same as before */ ) : /* same as before */ {}

    void pre_processor (size_t iter, Particle<mini> &particle)
    {
        inc_weight_.resize(particle.size());

        if (iter == 1) {
            alpha_.clear();
            alpha_.push_back(0);
        }

        if (iter == T_) {
            alpha_.push_back(1);
            return;
        }

        inc_weight_base_.resize(particle.size());
        for (size_t i = 0; i != particle.size(); ++i) {
            inc_weight_base_ = 
                normal_log_pdf(sp.state(0), muT_, sdT_) -
                normal_log_pdf(sp.state(0), mu0_, sd0_);
        }

        const double cess_star = 0.99;
        double lower = alpha_.end();
        double upper = 1.05;
        double alpha = lower + 0.05;
        double alpha_last = alpha_.end();
        double error = 1e-3 * (1 - ess_star_);
        while (std::abs(upper - lower) > error && lower <= 1) {
            double alpha_diff = alpha - alpha_last;
            for (size_t i = 0; i != particle.size(); ++i)
                inc_weight_[i] = alpha_diff * inc_weight_base_[i];
            double cess = particle.weight_set().cess(
                    inc_weight_.begin(), true);
            if (cess < cess_star) {
                upper = alpha;
                alpha = 0.5 * (alpha + lower);
            } else {
                lower = alpha;
                alpha = 0.5 * (alpha + upper);
            }
            alpha_.push_back(alpha);
        }
    }

    size_t move_state (size_t iter, SingleParticle<mini> sp)
    { /* Same as before */ }

    void post_processor (size_t, Particle<mini> &particle)
    { /* same as before */ }

    private :

    std::vector<double> alpha_;
    std::vecotr<double> inc_weight_base_;
    // Same as before

    double alpha (size_t iter) {return alhpa_[iter];}
};
