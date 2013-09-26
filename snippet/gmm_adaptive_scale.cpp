template <std::size_t R>
class GMM_AdaptiveScale
{
    public :

    GMM_AdaptiveScale (const Sampler<GMM<R> > *sampler_ptr) :
        sampler_ptr_(sampler_ptr) {}

    std::size_t operator() (std::size_t, Particle<GMM<R> > &particle)
    {
        double res[GMM_Moments<R, 2>::Dim];
        for (std::size_t j = 0; j != GMM_Moments<R, 2>::Dim; ++j)
            res[j] = sampler_ptr_->monitor("moments").record(j);
        particle.value().mu_scale() =
            GMM_Moments<R, 2>::mu_scale(res);
        particle.value().lambda_scale() =
            GMM_Moments<R, 2>::lambda_scale(res);
        particle.value().omega_scale() =
            GMM_Moments<R, 2>::omega_scale(res);
    }

    private :

    const Sampler<GMM<R> > *sampler_ptr_;
}
