#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    std::vector<int> arr;
    std::vector<int> span;
    unsigned int max_size;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& copy);
    Span& operator=(const Span& rhs);
    ~Span();

    void    addNumber(int new_value);
    int     shortestSpan();
    int     longestSpan();
    void    addRange(std::vector<int>::iterator first
        , std::vector<int>::iterator last);


    void    printSpan(); // a suprimer
};



#endif