#include "RPN.hpp"

void _plus(std::stack<int> &s)
{
    if (s.size() < 2)
        throw(std::logic_error("Error!")) ;
    int tmp1 = s.top();
    s.pop();
    int tmp2 = s.top();
    s.pop();
    s.push(tmp2 + tmp1);
}


void _dif(std::stack<int> &s)
{
    if (s.size() < 2)
        throw(std::logic_error("Error!")) ;
    int tmp1 = s.top();
    s.pop();
    int tmp2 = s.top();
    s.pop();
    s.push(tmp2 - tmp1);
}


void _mult(std::stack<int> &s)
{
    if (s.size() < 2)
        throw(std::logic_error("Error!")) ;
    int tmp1 = s.top();
    s.pop();
    int tmp2 = s.top();
    s.pop();
    s.push(tmp2 * tmp1);
}


void _div(std::stack<int> &s)
{
    if (s.size() < 2)
        throw(std::logic_error("Error!"));
    int tmp1 = s.top();
    s.pop();
    int tmp2 = s.top();
    s.pop();
    if (tmp2 == 0)
        throw(std::logic_error("Error div by 0!"));
    s.push(tmp2 / tmp1);
}


void    rpn(std::string line)
{
    int             i;
    std::stack<int> s;

    i = 0;
    while (line[i])
    {
        if ('0' <= line[i] && line[i] <= '9' && (line[i+1] == 0 || line[i+1] == ' '))
            s.push(line[i] - '0');
        else if (line[i] == '+')
            _plus(s);
        else if (line[i] == '-')
            _dif(s);
        else if (line[i] == '*')
            _mult(s);
        else if (line[i] == '/')
            _div(s);
        else if (line[i] == ' ')
        {
            i++;
            continue ;
        }
        else
            throw(std::logic_error("Error!"));
        i++;
    }
    if (s.size() != 1)
        throw(std::logic_error("Error"));
    std::cout << s.top() << std::endl;
}