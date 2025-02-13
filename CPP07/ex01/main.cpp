#include "iter.hpp"

void print_elem(int &elem)
{
    std::cout << "elem " << elem << std::endl;
}

void add_one(int &elem)
{
    elem++;
}

int main()
{
    int arr[6] = {1, 123, 33, 12, 1, 0};

    iter(arr, 6, print_elem);
    iter(arr, 6, add_one);
    std::cout << "------" << std::endl;
    iter(arr, 6, print_elem);
}
