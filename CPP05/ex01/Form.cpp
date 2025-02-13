#include "Form.hpp"

Form::Form() : name("defForm"), is_sign(false), required_to_sign(150), required_to_exec(150) {}

Form::Form(const Form &copy) : name(copy.name), is_sign(false), required_to_sign(copy.required_to_sign)
    , required_to_exec(copy.required_to_exec) {}

Form::~Form() {}

Form&   Form::operator=(const Form& rhs)
{
    (void) rhs;
    return *this ;
}

Form::Form(std::string _name, int sign, int exec) : name(_name), is_sign(false), required_to_sign(sign),
    required_to_exec(exec)
{
    if (sign < 1 || exec < 1)
        throw(GradeTooHighException());
    else if (sign > 150 || exec > 150)
        throw(GradeTooLowException());
}

void    Form::beSigned(const Bureaucrat &mr_bureaucrat)
{
    if (mr_bureaucrat.getGrade() > required_to_sign)
        throw (GradeTooLowException());
    is_sign = true;
}

const std::string   Form::getName() const
{
    return name;
}

bool    Form::getIsSign() const
{
    return is_sign;
}

 int   Form::getRequiredSign() const
{
    return required_to_sign;
}

 int   Form::getRequiredExec() const
{
    return required_to_exec;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High Exception";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low Exception";
}

std::ostream&   operator<<(std::ostream& stream, const Form& form)
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