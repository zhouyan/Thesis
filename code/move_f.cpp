std::size_t move_f (std::size_t iter, Particle<T> &particle)
{
    const std::size_t N = particle.size();
    std::vector<double> inc_weight(N);
    for (std::size_t i = 0; i != N; ++i) {
        cxx11::normal_distribution<double> rnorm(0, 1);
        particle.value().state(i, 0) = rnorm(particle.rng(i));
        inc_weight[i] = cal_inc_weight(
                particle.value().state(i, 0));
    }
    particle.weight_set().add_log_weight(inc_weight.begin());
}
