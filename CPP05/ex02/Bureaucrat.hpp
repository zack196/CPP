#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int               grade;   
public:
    //Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& rhs);

    Bureaucrat(std::string _name, int _grade);
    const std::string   getName() const;
    int                 getGrade() const;

    void                promote();
    void                demote();
    void                signForm(AForm &form) const;

    void executeForm(AForm const & form);


    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw();            
    };    

};

std::ostream&   operator<<(std::ostream &stream, Bureaucrat &mr_bureuacrat);

#endif