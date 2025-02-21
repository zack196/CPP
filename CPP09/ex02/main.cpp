#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        if (!check_input(av + 1))
        {
            std::cerr << "Error!\n" ;
            return 1;
        }

        std::list<int>      l;
        std::vector<int>    v;
        int i = 1;
        while (av[i])
        {
            l.push_back(std::atol(av[i]));
            v.push_back(std::atol(av[i]));
            i++;
        }
        
        clock_t t;
        
        
        std::cout << "Before:   ";
        for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        t = clock();
        merge_sort_list(l);
        std::cout << "After:   ";
        for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << l.size() << " elements with std::list : " 
            << static_cast<float>(t) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
        
        t = clock();
        
        merge_sort_vector(v);
        
        std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " 
            << static_cast<float>(t) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
        
        return 0;
    }
    std::cerr << "not enough argument\n";
    return 1;
}