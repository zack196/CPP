#include "RPN.hpp"

int main(int ac, char *av[])
{
    try
    {
        if (ac != 2)
            throw(std::runtime_error("Error input"));

        RPN calculator( (std::string(av[1])) );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}