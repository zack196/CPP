#include "PmergeMe.hpp"

int getNbr(const std::string& strNbr)
{
    std::istringstream  ss(strNbr);

    for (size_t i = 0; i < strNbr.size(); i++)
    {
        if (i == 0 && strNbr[i] == '+' && strNbr.size() != 1)
            continue ;
        if (!isdigit(strNbr[i]))
            throw(std::runtime_error("Error"));
    }
    
    errno = 0;
    char* endptr = NULL;
    long val = std::strtol(strNbr.c_str(), &endptr, 10);

    if (errno == ERANGE || val > INT_MAX  || val < 0) 
        throw(std::runtime_error("Error"));

    return static_cast<int>(val);
}

int main(int ac, char** av)
{
    try
    {
        if (ac == 1)
            throw(std::runtime_error("Error: no input"));
        std::vector<int> vecInput;
        std::deque<int> deqInput;
        for (int i = 1; i < ac; i++)
        {
            int nbr = getNbr(std::string(av[i])) ;
            vecInput.push_back(nbr);
            deqInput.push_back(nbr);
        }
        
        std::cout << "before: ";
        for (size_t i = 0; i < vecInput.size(); i++)
            std::cout << vecInput[i] << " ";
        std::cout << std::endl;

        // vector :
        PmergeMe p;

        clock_t start = std::clock();
        vecInput = p.mergeInsertSortVector(vecInput);
        clock_t  end = std::clock();

        std::cout << "after: ";
        for (size_t i = 0; i < vecInput.size(); i++)
            std::cout << vecInput[i] << " ";
        std::cout << std::endl;

        double elapsed_us = (end - start) * 1e6 / CLOCKS_PER_SEC;
        
        std::cout << "Time to process a range of " << vecInput.size() 
            << " elements with std::vector : " << elapsed_us << " us\n";
        
        // deque:
        start = std::clock();
        deqInput = p.mergeInsertSortDeque(deqInput);
        end = std::clock();
        
        elapsed_us = (end - start) * 1e6 / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << deqInput.size() 
            << " elements with std::deque : " << elapsed_us << " us\n";


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    



}