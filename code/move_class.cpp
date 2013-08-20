#include <vsmc/smp/backend_seq.hpp>

class move : public MoveSEQ<T>
{
    public :

    void pre_processor (
            std::size_t iter, Particle<T> &particle)
    {
        inc_weight_.resize(particle.size());
    }

    std::size_t move_state (
            std::size_t iter, SingleParticle<T> sp)
    {
        cxx11::normal_distribution<double> rnorm(0, 1);
        sp.state(0) = rnorm(sp.rng());
        inc_weight_[sp.id()] = cal_inc_weight(sp.state(0));
    }

    void post_processor (
            std::size_t iter, Particle<T> &particle)
    {
        particle.weight_set().add_log_weight(inc_weight_.begin());
    }

    private :

    std::vector<double> inc_weight_;
};
