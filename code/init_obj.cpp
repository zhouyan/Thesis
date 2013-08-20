std::function<
    std::size_t (Particle<T> &, void *)
    > init_obj(init_func);
sampler.init(init_obj);
