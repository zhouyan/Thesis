template <typename T>
struct SizeType
{
    typedef std::size_t size_type;
};

template <>
struct SizeType<SomeSpecialType>
{
    typedef int size_type;
};

template <typename T>
struct Sampler
{
    typedef typename SizeType<T>::type size_type;
};
