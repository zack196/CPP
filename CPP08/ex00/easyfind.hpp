#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <exception>

template <typename T>
int easyfind(T cont, int to_find)
{
    typename T::iterator it;
    it = std::find(cont.begin(), cont.end(), to_find);
    if (it == cont.end())
        throw(std::runtime_error("value not found!"));
    return *it;
}


#endif