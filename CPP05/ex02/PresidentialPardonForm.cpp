#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), target("defTarget") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), target(copy.target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("Presidential", 25, 5), target(_target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    target = rhs.target;
    return *this ;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSign())
        throw(FormNotSingedException());
    if (this->getRequiredExec() < executor.getGrade())
        throw(GradTooLowToExec());
    
    std::cout << target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}
