#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int u) : max_size(u) {}

Span::Span(const Span& copy) : max_size(copy.max_size), arr(copy.arr) {}

Span&   Span::operator=(const Span& rhs)
{
    if (&rhs != this)
    {
        this->arr = rhs.arr;
        this->max_size = rhs.max_size;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
    if (arr.size() < max_size)
        arr.push_back(nbr);
    else
        throw(std::logic_error("max size reached"));
}

int     Span::shortestSpan()
{
    vector span_vector(arr);
    
    std::sort( span_vector.begin(), span_vector.end() );
    std::adjacent_difference( span_vector.begin(), span_vector.end()
        , span_vector.begin() );
    if (span_vector.size() < 2)
        throw( std::logic_error("span have less than 2 values!") );
    std::rotate( span_vector.begin(), span_vector.begin() + 1
                    , span_vector.end() );
    span_vector.pop_back();
    return *std::min_element(span_vector.begin(), span_vector.end());
}

int     Span::longestSpan()
{
    if (arr.size() < 2)
        throw( std::logic_error("span have less than 2 values!") );
    return *std::max_element( arr.begin(), arr.end() ) 
        - *std::min_element( arr.begin(), arr.end() ) ;
}

void Span::addLargeNumbers(vector::iterator begin, vector::iterator end)
{
    if (std::distance(begin, end) + arr.size() <= max_size)
        for (vector::iterator i = begin; i != end; i++)
            addNumber(*i);
    else
        throw(std::runtime_error("error adding vector to Span!"));
}