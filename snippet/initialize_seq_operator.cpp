std::size_t operator() (Particle<T> &particle, void *param)
{
    this->initialize_param(particle, param);
    this->pre_processor(particle);
    std::size_t acc = 0;
    for (std::size_t i = 0; i != particle.size(); ++i) {
        acc += this->initialize_state(
                SingleParticle<T>(i, particle));
    }
    this->post_processor(particle);

    return acc;
}
