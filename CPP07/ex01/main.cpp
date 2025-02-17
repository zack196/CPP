#include "iter.hpp"

template<typename T>
void print_elem(T &elem)
{
    std::cout << "elem " << elem << std::endl;
}

template<typename T>
void incriment(T &elem)
{
    elem++;
}

int main()
{
    int  intArr[6] = {1, 123, 33, 12, 1, 0};

    iter(intArr, 6, print_elem<int>);

    iter(intArr, 6, incriment<int>);
    
    std::cout << "------" << std::endl;
    
    iter(intArr, 6, print_elem<int>);
}
