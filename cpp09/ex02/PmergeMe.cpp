#include "PmergeMe.hpp"

void printVector(std::vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    (void) copy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
    (void) rhs;
    return *this;
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe(){}

std::deque<int> PmergeMe::getJacobDeque(const int size)
{
    std::deque<int> jac;
    int J0 = 0;
    int J1 = 1;
    jac.push_back(J1);
    while (true)
    {
        int Jn = J1 + 2 * J0;
        if (Jn > size)
            break ;
        jac.push_back(Jn);
        J0 = J1;
        J1 = Jn;
    }
    return jac;    
}

void PmergeMe::insertPendDeque(std::deque<int>& pend, std::deque<int>& mainChain)
{
    std::deque<int> jacob = getJacobDeque(pend.size());
    std::deque<bool> inserted(pend.size(), false);
    
    for (int k = jacob.size() - 1; k > 0; k--)
    {
        for (int i = jacob[k] - 1 ; i >= static_cast<int>(jacob[k - 1]); i--)
        {
            if (i >= 0 && i < static_cast<int>(pend.size()))
            {
                std::deque<int>::iterator pos = std::lower_bound(mainChain.begin()
                    , mainChain.end(), pend[i]);
                mainChain.insert(pos, pend[i]);
                inserted[i] = true;
            }
        }
    }
    for (int i = pend.size() - 1; i >= 0; --i)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin()
                , mainChain.end(), pend[i]);
            mainChain.insert(pos, pend[i]);
        }
    }
}

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& input)
{
    if (input.size() < 2)
        return input;

    std::deque<int> mainChain;
    std::deque<int> pend;

    for (size_t i = 0; i < input.size() - 1; i += 2)
    { 
        if (input[i] > input[i + 1])
        {
            mainChain.push_back(input[i]);
            pend.push_back(input[i + 1]);
        }
        else
        {
            mainChain.push_back(input[i + 1]);
            pend.push_back(input[i]);
        }
    }
    if (input.size() % 2 == 1)
        pend.push_back(input[input.size() - 1]);

    mergeInsertSortDeque(mainChain);
    insertPendDeque(pend, mainChain);

    return mainChain;
}


std::vector<int> PmergeMe::getJacobVector(const int size)
{
    std::vector<int> jac;
    int J0 = 0;
    int J1 = 1;
    jac.push_back(J1);
    while (true)
    {
        int Jn = J1 + 2 * J0;
        if (Jn >= size)
            break ;
        jac.push_back(Jn);
        J0 = J1;
        J1 = Jn;
    }
    return jac;    
}// 0 1 1 3 5 11 21 43

void PmergeMe::insertPendVector(std::vector<int>& pend, std::vector<int>& mainChain)
{
    std::vector<int> jacob = getJacobVector(pend.size());
    std::vector<bool> inserted(pend.size(), false);
    
    for (int k = jacob.size() - 1; k > 0; --k)
    {
        for (int i = jacob[k] - 1; i >= static_cast<int>(jacob[k - 1]); i--)
        {
            if (i >= 0 && i < static_cast<int>(pend.size()))
            {
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
                mainChain.insert(pos, pend[i]);
                inserted[i] = true;
            }
        }
    }
    for (int i = pend.size() - 1; i >= 0; --i)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin()
                , mainChain.end(), pend[i]);
            mainChain.insert(pos, pend[i]);
        }
    }
    // printVector(mainChain);
    // printVector(pend);
}



std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& input)
{
    if (input.size() < 2)
        return input;

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    { 
        if (input[i] > input[i + 1])
        {
            mainChain.push_back(input[i]);
            pend.push_back(input[i + 1]);
        }
        else
        {
            mainChain.push_back(input[i + 1]);
            pend.push_back(input[i]);
        }
    }
    if (input.size() % 2 == 1)
        pend.push_back(input[input.size() - 1]);
    
    mainChain = mergeInsertSortVector(mainChain);
    insertPendVector(pend, mainChain);

    return mainChain;
}

