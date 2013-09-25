int main ()
{
    Sampler<T> sampler(N, Stratified, 0.5);
    sampler.init(init_f);             // Step 1.
    sampler.move(move_f, false);      // Step 2.(a)
    sampler.mcmc(mcmc_f1, true);      // Step 2.(c)
    sampler.mcmc(mcmc_f2, true);      // Step 2.(c)
    sampler.path_sampling(path_eval); // Path sampling
    // Importance sampling estimates of moments
    sampler.monitor("moments", 2, moments_eval);

    // Runing the algorithm
    sampler.initialize(param);
    sampler.iterate(IterNum);

    // Output to file
    std::ofstream output("sampler_file");
    output << sampler << std::endl;
    output.close();

    return 0;
}
