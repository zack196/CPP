#include "easyfind.hpp"

int main()
{
    std::vector<int> a;

    a.push_back(12);
    a.push_back(72);
    a.push_back(18);
    a.push_back(34);
    a.push_back(8);
    a.push_back(112);

    std::list<int> b;

    b.push_back(15);
    b.push_back(49);
    b.push_back(35);
    b.push_back(1);
    b.push_back(5);

    std::deque<int> c;

    c.push_back(19);
    c.push_back(9);
    c.push_back(45);
    c.push_back(23);
    c.push_back(89);
    

    try
    {
        easyfind(a, 8);
        easyfind(a, 100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    try
    {
        easyfind(b, 5);
        easyfind(b, 16);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    try
    {
        easyfind(c, 89);
        easyfind(c, 8);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}
