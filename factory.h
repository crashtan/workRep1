template <typename T, typename A1>
std::unique_ptr<T> factory(A1&& a1)
{
    return std::unique_ptr<T>(new T(std::forward<A1>(a1)));
}
