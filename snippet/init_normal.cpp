// Definition of constants: N, K

typedef StateMatrix<RawMajor, K, double> T;

struct Param { double mean; double sd; };

std::size_t init_f (Particle<T> &particle, void *param)
{
    const Param *p = static_cast<const Param *>(param);
    std::normal_distribution<double> rnorm(p->mean, p->sd);
    for (std::size_t i = 0; i != particle.size(); ++i) {
        for (std::size_t k = 0; k != K; ++k) {
            particle.value().state(i, k) =
                rnorm(particle.rng(i));
        }
    }
}
