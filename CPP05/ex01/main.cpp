#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    try
    {
        Bureaucrat bur("zakaria", 99);
        Form f("tax", 100, 100);
        bur.signForm(f);
        bur.demote();
        bur.demote();//101
        bur.signForm(f);
        bur.promote();
        bur.signForm(f);//100
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}