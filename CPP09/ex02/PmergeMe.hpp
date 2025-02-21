#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <time.h>

bool check_input(char **av);
void    merge_sort_list(std::list<int> &l);
void    merge_sort_vector(std::vector<int> &v);

#endif