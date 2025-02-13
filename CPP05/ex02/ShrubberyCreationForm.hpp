#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    //Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm&    operator=(const ShrubberyCreationForm& rhs);

    ShrubberyCreationForm(std::string _target);
    virtual void execute(Bureaucrat const & executor) const;
};


#endif