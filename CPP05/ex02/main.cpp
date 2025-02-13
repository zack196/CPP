#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        try
        {
            Bureaucrat bur("ZAKARIA", 100);
            ShrubberyCreationForm sh("home");
            bur.signForm(sh);
            sh.execute(bur);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat bur("ZAKARIA", 40);
            RobotomyRequestForm rob("deha");
            bur.signForm(rob);
            bur.executeForm(rob);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat bur("Zakaria", 5);
            PresidentialPardonForm  pre("Zafzafi");
            bur.demote();
            bur.signForm(pre);
            bur.promote();
            bur.executeForm(pre);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}