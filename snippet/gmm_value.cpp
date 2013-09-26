template <std::size_t R>
class GMM :
    public StateMatrix<RawMajor, 3 * R, double>
{
    public :

    GMM (std::size_t N) :
        StateMatrix<RawMajor, 3 * R, double>(N),
        mu_scale_(1), lambda_scale_(1), omega_scale_(1) {}

    static const std::size_t ComponentNumber = R;

    static std::size_t mu_idx (std::size_t j)
    { return j; }

    static std::size_t lambda_idx (std::size_t j)
    { return R + j; }

    static std::size_t omega_idx (std::size_t j)
    { return R * 2 + j; }

    double mu_scale () const { return mu_scale_; }
    double &mu_scale () {return mu_scale_; }

    double lambda_scale () const { return lambda_scale_; }
    double &lambda_scale () {return lambda_scale_; }

    double omega_scale () const { return omega_scale_; }
    double &omega_scale () {return omega_scale_; }

    double alpha (std::size_t t) const;
    double &alpha (std::size_t t);

    void read_data (const std::string &data_file);

    double log_likelihood (std::size_t i) const;
    double log_prior (std::size_t i) const;

    private :

    double mu_scale_, lambda_scale_, omega_scale_;
    std::vector<double> alpha_;
    std::vector<double> data_;
};
