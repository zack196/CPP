#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string   name;
    bool                is_sign;
    const int           required_to_sign;
    const int           required_to_exec;
public:
    //Orthodox Canonical Form
    AForm();
    AForm(const AForm &copy);
    virtual ~AForm();
    AForm&   operator=(const AForm& rhs);

    AForm(std::string _name, int sign, int exec);
    void    beSigned(const Bureaucrat &mr_bureaucrat);

    const std::string   getName() const;
    bool                getIsSign() const;
    int                 getRequiredSign() const;
    int                 getRequiredExec() const;

    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };

    virtual void execute(Bureaucrat const & executor) const = 0;

    class FormNotSingedException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };


    class GradTooLowToExec : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };
};
std::ostream&   operator<<(std::ostream& stream, const AForm &form);


#endif