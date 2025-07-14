#ifndef PERGE_ME_HPP
#define PERGE_ME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <limits.h>
#include <ctime>
#include <cerrno>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& );
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe&);

		// PmergeMe(std::vector<int> vecInput, std::deque<int> deqInput);
		// Deque:
		std::deque<int> getJacobDeque(const int size);
		void insertPendDeque(std::deque<int>& pend, std::deque<int>& mainChain);
			std::deque<int> mergeInsertSortDeque(const std::deque<int>& input);

		// Vector:
		std::vector<int> getJacobVector(const int size);
		void insertPendVector(std::vector<int>& pend, std::vector<int>& mainChain);
		std::vector<int> mergeInsertSortVector(const std::vector<int>& input);

};
#endif