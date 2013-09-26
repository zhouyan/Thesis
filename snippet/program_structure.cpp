int main ()
{
    Sampler<T> sampler(N, Stratified, 0.5);

    sampler.init(init_f);             // Step 1.
    sampler.move(move_f, false);      // Step 2.(a)
    sampler.mcmc(mcmc_f1, true);      // Step 2.(c)
    sampler.mcmc(mcmc_f2, true);      // Step 2.(c)

    // Path sampling
    sampler.path_sampling(path_eval);

    // Importance sampling estimates of moments
    sampler.monitor("moments", 2, moments_eval);

    // Runing the algorithm
    sampler.initialize(param);
    sampler.iterate(IterNum);

    // Results of path sampling
    std::cout << "Path sampling: " << std::endl;
    std::cout << sampler.path_sampling() << std::endl;

    // Output importance sampling approximation
    // and other aspects of the history of the sampler
    std::ofstream output("sampler_file");
    output << sampler << std::endl;
    output.close();

    return 0;
}
