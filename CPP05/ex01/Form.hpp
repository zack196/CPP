#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   name;
    bool                is_sign;
    const int           required_to_sign;
    const int           required_to_exec;
public:
    //Orthodox Canonical Form
    Form();
    Form(const Form &copy);
    ~Form();
    Form&   operator=(const Form& rhs);

    Form(std::string _name, int sign, int exec);
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
};
std::ostream&   operator<<(std::ostream& stream, const Form &form);


#endif