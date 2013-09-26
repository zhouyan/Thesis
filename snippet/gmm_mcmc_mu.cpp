template <std::size_t R>
class GMM_MCMC_Mu : public MoveOMP<GMM<R> >
{
    public :

    std::size_t move_state (
            std::size_t iter, SingleParticle<GMM<R> > sp)
    {
        // Step 1.
        double log_target =
            sp.particle().value().log_likelihood(sp.id()) +
            sp.particle().value().log_prior(sp.id());

        // Step 2.
        double backup[R];
        std::normal_distribution<double> rnorm(
                0, sp.particle().value().mu_scale());
        for (std::size_t j = 0; j != R; ++j) {
            std::size_t mu_idx = GMM<R>::mu_idx(j);
            backup[mu_idx] = sp.state(mu_idx);
            sp.state(mu_idx) += rnorm(sp.rng());
        }

        // Step 3.
        double log_target_proposed =
            sp.particle().value().log_likelihood(sp.id()) +
            sp.particle().value().log_prior(sp.id());

        // Step 4.
        std::uniform_distribution<double> runif(0, 1);
        double log_u = std::log(runif(sp.rng()));

        // Step 5.
        double log_prob = log_target_proposed - log_target;
        if (log_u > log_prob) {
            for (std::size_t j = 0; j != R; ++j) {
                std::size_t mu_idx = GMM<R>::mu_idx(j);
                sp.state(mu_idx) = backup[mu_idx];
            }
            return 0;
        }
        return 1;
    }
};
