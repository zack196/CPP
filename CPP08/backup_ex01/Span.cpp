#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& copy) : arr(copy.arr), span(copy.span), max_size(copy.max_size) {}

Span::~Span() {}

Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        this->max_size = rhs.max_size;
        this->arr = rhs.arr;
        this->span = rhs.span;
    }
    return *this;
}

void    Span::addNumber(int new_value)
{
    if (arr.size() < max_size)
    {
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
            span.push_back(abs(new_value - *it));
        arr.push_back(new_value);
    }
    else
        throw(std::logic_error("error adding an element"));
}

int     Span::shortestSpan()
{
    if (!span.size())
        throw (std::logic_error("not enough element for span !"));
    return *min_element(span.begin(), span.end());
}

int     Span::longestSpan()
{
    if (!span.size())
        throw (std::logic_error("not enough element for span !"));
    return *max_element(span.begin(), span.end());
}

void    Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (std::distance(first, last) + arr.size() <= max_size)
    {
        for (std::vector<int>::iterator it = first; it != last; it++)
            addNumber(*it);
    }
    else
        throw(std::logic_error("range exede the max size"));
}

void    Span::printSpan()
{
    int i = 0;
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
        std::cout << "span["<< i++ << "] = " << *it << std::endl;
}
