#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Bureaucrat b("zakaria1" , 155);
        Bureaucrat c("zakaria2" , 150);
        c.demote();
        Bureaucrat f("zakaria3" , 1);
        f.promote();
        std::cout << c << std::endl;       
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}