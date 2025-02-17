#include <iostream>
#include <cmath>
#include <limits>

template<typename T>
bool is_equal(T a, T b)
{
    return a == b;
}
template<>
bool is_equal<float>(float a, float b)
{
    return fabs(a - b) < std::numeric_limits<float>::epsilon();
}
int main()
{
    return 0;
}