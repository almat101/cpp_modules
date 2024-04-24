#ifndef whatever_hpp
#define whatever_hpp


//definition of template T
template<typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

template<typename T>
T min(T x, T y)
{
    return (x > y) ? y : x;
}

template<typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif