#include "PmergeMe.hpp"

bool check_input(char **av)
{
    int i = 0;
    while (av[++i])
    {
        int j = 0;
        if (av[i][j] == '+' || av[i][j] == '-')
            if (av[i][j++] == '-')
                return false;
        while (av[i][j])
        {
            if (!isdigit(av[i][j]))
                return false;
            j++;
        }
    }
    return true;
}

void    merge_list(std::list<int> &l, std::list<int> left, std::list<int> right)
{
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        if (left.size() && right.size() && left.front() < right.front())
        {
            *it = left.front();
            left.pop_front();
        }
        else if (left.size() && right.size() && left.front() > right.front())
        {
            *it = right.front();
            right.pop_front();
        }
        else if (right.size())
        {
            *it = right.front();
            right.pop_front();
        }
        else if (left.size())
        {
            *it = left.front();
            left.pop_front();
        }
    }
}

void    merge_sort_list(std::list<int> &l)
{
    if (l.size() <= 1)
        return ;
    std::list<int> left;
    std::list<int> right;
    std::list<int>::iterator  it = l.begin();
    int mid = l.size() / 2;
    int i = 0;

    while (i < mid)
    {
        left.push_back(*it);
        i++;
        it++;
    }
    while (i < (int)l.size())
    {
        right.push_back(*it);
        it++;
        i++;
    }
    merge_sort_list(left);
    merge_sort_list(right);
    merge_list(l, left, right);
}

void    merge_vector(std::vector<int> &v, std::vector<int> left, std::vector<int> right)
{
    std::vector<int>::iterator il = left.begin();
    std::vector<int>::iterator ir = right.begin();
    std::vector<int>::iterator it = v.begin();

    while (il != left.end() && ir != right.end())
    {
        if (*il < *ir)
        {
            *it = *il;
            il++;
            it++;
        }
        else
        {
            *it = *ir;
            ir++;
            it++;
        }
    }
    while (il != left.end())
    {
        *it = *il;
        it++;
        il++;
    }
    while (ir != right.end())
    {
        *it = *ir;
        it++;
        ir++;
    }
}

void    merge_sort_vector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return ;
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int>::iterator  it = v.begin();
    int mid = v.size() / 2;
    int i = 0;

    while (i < mid)
    {
        left.push_back(*it);
        i++;
        it++;
    }
    while (i < (int)v.size())
    {
        right.push_back(*it);
        it++;
        i++;
    }
    merge_sort_vector(left);
    merge_sort_vector(right);
    merge_vector(v, left, right);
}