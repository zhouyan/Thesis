template <typename T>
struct SizeTypeTrait
{
    typedef std::size_t size_type;
};

template <>
struct SizeTypeTrait<SomeSpecialType>
{
    typedef int size_type;
};

template <typename T>
struct Sampler
{
    typedef typename SizeTypeTrait<T>::type size_type;
};
