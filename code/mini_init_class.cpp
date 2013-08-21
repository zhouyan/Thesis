class mini_init :
{
    public :

    mini_init (double mu0, double sd0) : mu0_(mu0), sd0_(sd0) {}

    size_t operator() (SingleParticle<mini> sp)
    {
        normal_distribution<> rnorm(mu0, sd0);
        sp.state(0) = rnorm(sp.rng());

        return 1;
    }

    private :

    double mu0_, sd0_;
};

// in main function
sampler.init(InitializeAdapter<mini, BASE_INIT>(
	    mini_init(mu0, sd0)));
