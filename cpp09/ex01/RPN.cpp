#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy)
{
    _numbers = copy._numbers;
}

RPN& RPN::operator=(const RPN& rhs) 
{
    _numbers = rhs._numbers;
    return *this ;
}

RPN::RPN(std::string expresion)
{
    for (size_t i = 0; i < expresion.size(); i++)
    {
        if ( isdigit(expresion[i]) )
            _numbers.push(expresion[i] - '0');
        
        if (i == 0 && isdigit(expresion[i]))
            continue ;
        
        if (isdigit(expresion[i]) && expresion[i - 1] != ' ')
            throw(std::runtime_error("Error"));

        if ((expresion[i] == '-' || expresion[i] == '+' ||expresion[i] == '/' ||expresion[i] == '*') &&  (_numbers.size() < 2 || expresion[i - 1] != ' '))
            throw(std::runtime_error("Error"));

        if (expresion[i] == '-')
        {
            int a = _numbers.top();
            _numbers.pop();
            int b = _numbers.top();
            _numbers.pop();
            _numbers.push(b - a);
        }

        if (expresion[i] == '+')
        {
            int a = _numbers.top();
            _numbers.pop();
            int b = _numbers.top();
            _numbers.pop();
            _numbers.push(b + a);
        }

        if (expresion[i] == '*')
        {
            int a = _numbers.top();
            _numbers.pop();
            int b = _numbers.top();
            _numbers.pop();
            _numbers.push(b * a);
        }

        if (expresion[i] == '/')
        {
            int a = _numbers.top();
            _numbers.pop();
            int b = _numbers.top();
            _numbers.pop();
            if (b == 0)
                throw(std::runtime_error("Error"));
            _numbers.push(b / a);
        }
    }

    if (_numbers.size() != 1)
        throw(std::runtime_error("Error"));

    std::cout << _numbers.top() << std::endl;
}
