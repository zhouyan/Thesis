// Using a function pointer
double Mean; // Global variable
double SD;   // Global variable
double target_f (double x)
{
    return normal_pdf(x, Mean, SD);
}

void update_mcmc ( /* same as before */)
{
    // ...
    Mean = mean;
    SD = sd;
    double p = prob(old_val, new_val, &target_f);
    // ...
}

// Using a functor
class TargetC
{
    public :

    TargetC (double mean, double sd) :
        mean_(mean), sd_(sd) {}

    bool operator () (double x) const
    {
        return normal_pdf(x, mean_, sd_);
    }

    private :

    double mean_, sd_;
};

void update_mcmc ( /* same as before */)
{
    // ...
    double p = prob(old_val, new_val, TargetC(mean, sd));
    // ...
}

// Using a lambda expression
void update_mcmc ( /* same as before */ )
{
    // ...
    double p = prob(old_val, new_val,
            [=] (double x) -> double {
                return normal_pdf(x, mean, sd);
            });
    // ...
}
