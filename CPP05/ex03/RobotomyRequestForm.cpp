#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("defaultTar") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("Robotomy", 72, 45), target(_target) {}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    target = rhs.target;
    return *this ;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSign())
        throw(FormNotSingedException());
    if (this->getRequiredExec() < executor.getGrade())
        throw(GradTooLowToExec());
    
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << "robotomized has failed!" << std::endl;
}

