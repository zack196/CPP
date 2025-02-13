#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();
    RobotomyRequestForm&    operator=(const RobotomyRequestForm& rhs);

    RobotomyRequestForm(std::string _target);
    void execute(Bureaucrat const & executor) const;
};

#endif