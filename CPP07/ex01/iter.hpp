#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T, typename F >
void iter(T* array, int lenght, void (*fct)(F))
{
    for (int i = 0; i < lenght; i++)
        fct(array[i]);
}

#endif