template <typename T, typename D = Virtual>
class InitializeSEQ
{
    virtual std::size_t initialize_state (SingleParticle<T>) = 0;
    virtual void initialize_param (Particle<T> &, void *);
    virtual void pre_processor (Particle<T> &);
    virtual void post_processor (Particle<T> &);

    std::size_t operator() (Particle<T>, void *);
};
