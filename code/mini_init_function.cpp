std::size_t mini_init (SingleParticle<mini> sp)
{
    normal_distribution<> rnorm(mu0, sd0);
    sp.state(0) = rnorm(sp.rng());

    return 1;
}

// in main function
sampler.init(InitializeAdapter<mini, BASE_INIT>(mini_init));
