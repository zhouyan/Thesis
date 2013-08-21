class mini_move : public BASE_MOVE<mini>
{
    public :

    mini_move (
            double mu0, double sd0,
            double muT, double sdT, size_t T) :
        mu0_(mu0), sd0_(sd0), muT_(muT), sdT_(sdT), T_(T),
        var0_(sd0 * sd0), varT_(sdT * sdT) {}

    void pre_processor (size_t, Particle<mini> &particle)
    {
        // Allocate space for the incremental weights
        inc_weight_.resize(particle.size());
    }

    size_t move_state (size_t iter, SingleParticle<mini> sp)
    {
        // Calculate the incremental weights
        inc_weight_[sp.id()] =
            (alpha(iter) - alpha(iter - 1)) * (
                    normal_log_pdf(sp.state(0), muT_, sdT_) -
                    normal_log_pdf(sp.state(0), mu0_, sd0_));

        // A Normal random walk
        NormalRW normal_rw;
        double m = mu(iter);
        double s = sd(iter);

        return normal_rw(sp.state(0), s, sp.rng(),
                [=] (double val) {
                    return normal_log_pdf(val, m, s);
                });
    }

    void post_processor (size_t, Particle<mini> &particle)
    {
        // Add the log of the incremental weights
        particle.weight_set().add_log_weight(
		inc_weight_.begin());
    }

    private :

    double mu0_, sd0_, muT_, sdT_, T_, var0_, varT_;
    std::vector<double> inc_weight_;

    double alpha (size_t t) const; // Compute $\alpha(t/T) = t/T$
    double mu (size_t t) const;    // Compute $\mu_t$
    double sd (size_t t) const;    // Compute $\sigma_t$
};
