#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

bool isPositiveInteger(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

std::vector<int> parseArguments(int ac, char** av) {
    std::vector<int> result;
    for (int i = 1; i < ac; ++i) {
        std::string token(av[i]);
        if (!isPositiveInteger(token)) {
            throw std::runtime_error("Error");
        }
        int number = std::atoi(token.c_str());
        if (number < 0)
            throw std::runtime_error("Error");
        result.push_back(number);
    }
    return result;
}

// Jacobsthal sequence generator
std::vector<size_t> getJacobsthalIndexes(size_t size) {
    std::vector<size_t> indexes;
    size_t j0 = 0, j1 = 1;
    indexes.push_back(j1);
    while (true) {
        size_t jn = j1 + 2 * j0;
        if (jn >= size)
            break;
        indexes.push_back(jn);
        j0 = j1;
        j1 = jn;
    }
    return indexes;
}

// Insertion using Jacobsthal order
void insertPend(std::vector<int>& mainChain, const std::vector<int>& pend) {
    std::vector<size_t> jac = getJacobsthalIndexes(pend.size());
    std::vector<bool> inserted(pend.size(), false);
    
    for (int k = jac.size() - 1; k > 0; --k) {
        for (int i = jac[k] - 1; i >= (int)jac[k - 1]; --i) {
            if (i >= 0 && i < (int)pend.size()) {
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
                mainChain.insert(pos, pend[i]);
                inserted[i] = true;
            }
        }
    }
    for (int i = pend.size() - 1; i >= 0; --i) {
        if (!inserted[i]) {
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(pos, pend[i]);
        }
    }
}

std::vector<int> mergeInsertSort(const std::vector<int>& input) {
    if (input.size() <= 1)
        return input;

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            pend.push_back(input[i]);
            mainChain.push_back(input[i + 1]);
        } else {
            pend.push_back(input[i + 1]);
            mainChain.push_back(input[i]);
        }
    }

    if (input.size() % 2 != 0)
        pend.push_back(input.back());

    mainChain = mergeInsertSort(mainChain);
    insertPend(mainChain, pend);

    return mainChain;
}

void run(int ac, char** av) {
    std::vector<int> input = parseArguments(ac, av);

    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    std::vector<int> resultVec = mergeInsertSort(input);
    clock_t endVec = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < resultVec.size(); ++i)
        std::cout << resultVec[i] << " ";
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << input.size() << " elements with std::vector: " << timeVec << " us" << std::endl;
}
int main(int ac, char **av)
{
    run(ac, av);
}