#include "Intern.hpp"

int main()
{
    try 
    {
        Intern intern;
        Bureaucrat bur("zack", 138);

        AForm* a = intern.makeForm("Shrubbery!", "home");
        bur.signForm(*a);
        bur.executeForm(*a);
        bur.promote();
        bur.executeForm(*a);
        delete a;
    }
    catch(const char * e)
    {
        std::cout << "the form named " << e <<" is not availible, the availible ones are : "
            << "Robotomy, Presidential, and Shrubbery." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}