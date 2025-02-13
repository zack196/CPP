#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("def-Bureaucrat") , grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        grade = rhs.grade;
    return *this ;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
    if (grade > 150)
        throw(GradeTooLowException());
    else if (grade < 1)
        throw(GradeTooHighException());
}

const std::string   Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade ;
}

void    Bureaucrat::promote()
{
    try
    {
        if (grade < 2)
            throw(GradeTooHighException());
        grade--;
    }
    catch(const GradeTooHighException& e)
    {
        std::cout << getName() << " can't be promoted because it will become " << e.what() << std::endl;
    }
}

void    Bureaucrat::demote()
{
    try
    {
        if (grade > 149)
            throw(GradeTooLowException());
        grade++;
    }
    catch(GradeTooLowException& e)
    {
        std::cout << getName() << " can't be demoted because it will become " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade Too High" ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade Too Low" ;
}

std::ostream&   operator<<(std::ostream &stream, Bureaucrat &mr_bureuacrat)
{
    stream << mr_bureuacrat.getName() << ", bureaucrat grade " << mr_bureuacrat.getGrade();
    return stream;
}
