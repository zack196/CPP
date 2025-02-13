# include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void) rhs;
    return *this;
}

AForm*  Intern::makeForm(std::string formName, std::string target)
{
    fct forms[] = {&Intern::makeShrubbery, &Intern::makeRobot, &Intern::makePresidential};
    int index = (formName == "Shrubbery") + 2 * (formName == "Robotomy")
        + 3 * (formName == "Presidential") - 1;
    if (index == -1)
        throw(formName.c_str());
    Intern i;
    return (this->*forms[index])(target);;
}

AForm*  Intern::makePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::makeRobot(std::string target)
{
    return new RobotomyRequestForm(target);
}
