#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef std::vector<int> vector;

class Span
{
private:
    unsigned int    max_size;
    vector          arr;
public:
    Span();
    Span(unsigned int u);
    Span(const Span& copy);
    ~Span();
    Span& operator=(const Span& rhs);
    
    void    addNumber(int nbr);
    int     shortestSpan();
    int     longestSpan();
    void addLargeNumbers(vector::iterator begin, vector::iterator end);

    void print_span()
    {
        for (vector::iterator i = arr.begin(); i != arr.end(); i++)
            std::cout << *i << ", ";
        std::cout << std::endl;
    }
};


#endif