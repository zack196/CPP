#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& copy);
    ~Intern();
    Intern& operator=(const Intern& rhs);

    AForm*  makeForm(std::string formName, std::string target);
    
    AForm*  makePresidential(std::string target);
    AForm*  makeShrubbery(std::string target);
    AForm*  makeRobot(std::string target);
};

typedef AForm* (Intern::*fct) (std::string);


#endif