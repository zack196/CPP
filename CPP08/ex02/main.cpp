#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "---- mstack iterator ----" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "---- mstack reverse iterator ----" << std::endl;
    MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
    MutantStack<int>::reverse_iterator r_ite = mstack.rend();
    while (r_it != r_ite)
    {
        std::cout << *r_it << std::endl;
        ++r_it;
    }

    std::cout << "----copy----" << std::endl;
    std::stack<int> s(mstack);
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}

// # include <list>
// int main()
// {
//     std::deque<int> mstack;

//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.front() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     mstack.push_back(0);
//     std::deque<int>::iterator it = mstack.begin();
//     std::deque<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     std::cout << "*** mstack ***" << std::endl;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
// }