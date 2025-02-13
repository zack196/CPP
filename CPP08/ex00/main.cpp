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
        std::cout << easyfind(a, 8) << std::endl;
        std::cout << easyfind(a, 100) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    try
    {
        std::cout << easyfind(b, 5) << std::endl;
        std::cout << easyfind(b, 16) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    try
    {
        std::cout << easyfind(c, 89) << std::endl;
        std::cout << easyfind(c, 8) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}
