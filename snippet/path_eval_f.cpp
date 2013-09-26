double path_eval (std::size_t iter,
        const Particle<T> &particle, double *res)
{
    for (std::size_t i = 0; i != particle.size(); ++i)
        res[i] = particle.value().log_likelihood(i);

    return particle.value().alpha(iter);
}
