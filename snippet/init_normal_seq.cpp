class init_c : public InitializeSEQ<T>
{
    public :

    init_c () : mean_(0), sd_(1) {}

    std::size_t initialize_state (SingleParticle<T> sp)
    {
        std::normal_distribution<double> rnorm(mean_, sd_);
        for (std::size_t k = 0; k != K; ++k)
            sp.state(k) = rnorm(sp.rng());
    }

    void initialize_param (Particle<T> &, void *param)
    {
        const Param *p = static_cast<const Param *>(param);
        mean_ = p->mean;
        sd_ = p->sd;
    }

    private :

    double mean_, sd_;
};

// In the main function, replace
// sampler.init(init_f); with
sampler.init(init_c());
