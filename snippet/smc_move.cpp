template <typename T>
std::size_t smc_move (std::size_t iter, Particle<T> &particle)
{
    // Calculate $\alpha_{\mathrm{diff}} = \alpha(t/T) - \alpha([t-1]/T)$
    const double alph_diff =
        particle.value().alpha(iter) -
        particle.value().alpha(iter - 1);

    // Calculate the logarithm of the incremental weights
    // $\tilde{w}_t = \alpha_{\mathrm{diff}} \log p(\data|\theta_t,\calM)$
    std::vector<double> log_inc_w(particle.size());
    for (std::size_t i = 0; i != particle.size(); ++i) {
        log_inc_w[i] =
            alpha_diff * particle.value().log_likelihood(i);
    }

    particle.weight_set().add_log_w(log_inc_weight.begin());

    return 0;
}

// in main function
sampler.move(smc_move<T>, false);
