class mini_move : public BASE_MOVE<mini>
{
    public :

    mini_move (
            const Sampler<mini> *sampler,
            /* same parameters as before */) :
        sampler_(sampler), scale_(1), /* same as before */ {}

    void pre_processor (size_t, Particle<mini> &particle)
    {
        inc_weight_.resize(particle.size());
        double r1 = sampler_->monitor("moments").record(0);
        double r2 = sampler_->monitor("moments").record(1);
        scale_ = r2 - r1 * r1;
    }

    size_t move_state (size_t iter, SingleParticle<mini> sp)
    {
        // Same as before
        
        return normal_rw(sp.state(0), scale_, sp.rng(),
                [=] (double val) {
                    return normal_log_pdf(val, m, s);
                });
    }

    void post_processor (size_t, Particle<mini> &particle)
    { /* same as before */ }

    private :

    const Sampler<mini> *const sampler_;
    double scale_;
    // Same as before
};

// In the main function
sampler.move(mini_move(&sampler, mu0, sd0, muT, sdT, T), false);
