sampler
    .mcmc(GMM_MCMC_Mu(), false)
    .mcmc(GMM_MCMC_Lambda(), true)
    .mcmc(GMM_MCMC_Omega(), true);
