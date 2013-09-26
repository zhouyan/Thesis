template <typename F>
void sort_f (std::size_t N, const double *input,
        double *output, const F &f)
{
    for (std::size_t i = 0; i != N; ++i)
        output[i] = f(input[i]);
    std::sort(output, output + N);
}
