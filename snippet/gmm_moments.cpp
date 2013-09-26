template <std::size_t R, std::size_t M>
class GMM_Moments : MonitorEvalOMP<GMM<R> >
{
    public :

    static const std::size_t Dim = R * Order * 3;

    static std::size_t mu_idx (std::size_t j, std::size_t m)
    { return j * Order + (m - 1); }

    static std::size_t lambda_idx (std::size_t j, std::size_t m)
    { return j * Order + (m - 1) + R * Order; }

    static std::size_t omega_idx (std::size_t j, std::size_t m)
    { return j * Order + (m - 1) + R * Order * 2; }

    static double mu_scale (const double *res);
    static double lambda_scale (const double *res);
    static double omega_scale (const double *res);

    void monitor_state(std::size_t, std::size_t,
            ConstSingleParticle<GMM<R> > csp, double *res)
    {
        // Record the first raw moment
        for (std::size_t j = 0; j != R; ++j) {
            res[mu_idx(j, 1)] = csp.state(GMM<R>::mu_idx(j));
            res[lambda_idx(j, 1)] = csp.state(GMM<R>::lambda_idx(j));
            res[omega_idx(j, 1)] = csp.state(GMM<R>::omega_idx(j));
        }

        // Record the second and up to Order raw moments
        for (std::size_t m = 2; m <= Order; ++m) {
            for (std::size_t j = 0; j != R; ++j) {
                res[mu_idx(j, m)] =
                    res[mu_idx(j, 1)] * res[mu_idx(j, m - 1)];
                res[lambda_idx(j, m)] =
                    res[lambda_idx(j, 1)] * res[lambda_idx(j, m - 1)];
                res[omega_idx(j, m)] =
                    res[omega_idx(j, 1)] * res[omega_idx(j, m - 1)];
            }
        }
    }
};
