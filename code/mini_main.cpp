int main ()
{
    const size_t N = 1000;
    const size_t T = 100;
    const double mu0 = -5; // $\mu_0$
    const double sd0 = 10; // $\sigma_0$
    const double muT = 5;  // $\mu_T$
    const double sdT = 1;  // $\sigma_T$

    Sampler<mini> sampler(N);

    sampler.init(InitializeAdapter<mini, BASE_INIT>(
                [=] (SingleParticle<mini> sp) -> size_t {
                    normal_distribution<> rnorm(mu0, sd0);
                    sp.state(0) = rnorm(sp.rng());
                    return 1;
                }));

    sampler.move(mini_move(mu0, sd0, muT, sdT, T), false);

    sampler.monitor("moments", 2,
            MonitorEvalAdapter<mini, BASE_MONITOR>(
                [] (size_t, size_t,
                    ConstSingleParticle<mini> csp,
                    double *res) {
                    res[0] = csp.state(0);
                    res[1] = res[0] * res[0];
                }));

    sampler.initialize().iterate(T);

    std::ofstream sampler_file;
    sampler_file.open("mini_sampler");
    sampler_file << sampler << std::endl;

    return 0;
}
