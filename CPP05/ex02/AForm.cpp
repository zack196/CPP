#include "AForm.hpp"

AForm::AForm() : name("defForm"), is_sign(false), required_to_sign(150), required_to_exec(150) {}

AForm::AForm(const AForm &copy) : name(copy.name), is_sign(false), required_to_sign(copy.required_to_sign)
    , required_to_exec(copy.required_to_exec) {}

AForm::~AForm() {}

AForm&   AForm::operator=(const AForm& rhs)
{
    (void) rhs;
    return *this ;
}

AForm::AForm(std::string _name, int sign, int exec) : name(_name), is_sign(false), required_to_sign(sign),
    required_to_exec(exec)
{
    if (sign < 1 || exec < 1)
        throw(GradeTooHighException());
    else if (sign > 150 || exec > 150)
        throw(GradeTooLowException());
}

void    AForm::beSigned(const Bureaucrat &mr_bureaucrat)
{
    if (mr_bureaucrat.getGrade() > required_to_sign)
        throw (GradeTooLowException());
    is_sign = true;
}

const std::string   AForm::getName() const
{
    return name;
}

bool    AForm::getIsSign() const
{
    return is_sign;
}

 int   AForm::getRequiredSign() const
{
    return required_to_sign;
}

 int   AForm::getRequiredExec() const
{
    return required_to_exec;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High Exception";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low Exception";
}

std::ostream&   operator<<(std::ostream& stream, const AForm& form)
{
    stream << "Form name : " << form.getName();
    if (form.getIsSign())
        stream << ", it is signed ";
    else
        stream << ", it is not signed ";
    stream << ", grade required to sign : " << form.getRequiredSign();
    stream << ", grade required to execute : " << form.getRequiredExec();
    return stream ;
}

const char* AForm::GradTooLowToExec::what() const throw()
{
    return "Grad Too Low To Exec";
}

const char* AForm::FormNotSingedException::what() const throw()
{
    return "Form Not Singed";
}
