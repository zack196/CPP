#ifndef RNF_HPP
#define RNF_HPP

#include "stack"
#include "iostream"

class RPN
{
private:
    std::stack<int> _numbers;
public:
    RPN();
    RPN(const RPN& copy);
    ~RPN();
    RPN& operator=(const RPN& rhs);

    RPN(std::string expresion);
};



#endif