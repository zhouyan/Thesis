void update_mcmc (double old_val, double &new_val,
        double mean, double sd)
{
    // generate new_val
    double p = prob(old_val, new_val, target);
    // accept or reject with probability p and modify new_val;
}
