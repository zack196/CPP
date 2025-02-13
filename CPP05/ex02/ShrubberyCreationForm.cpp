#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
    , target(copy.target)  {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    target = rhs.target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("Shrubbery", 145, 137)
    , target(_target){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSign())
        throw(FormNotSingedException());
    if (this->getRequiredExec() < executor.getGrade())
        throw(GradTooLowToExec());
    std::remove((target + "_shrubbery").c_str());
    std::ofstream    file((target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "         *         " << std::endl;
        file << "        ***        " << std::endl;
        file << "       *****       " << std::endl;
        file << "      *******      " << std::endl;
        file << "     *********     " << std::endl;
        file << "    ***********    " << std::endl;
        file << "   *************   " << std::endl;
        file << "  ***************  " << std::endl;
        file << " ***************** " << std::endl;
        file << "*******************" << std::endl;
        file << "         |         " << std::endl;
        file << "         |         " << std::endl;
        file.close();
    }
    else
        std::cerr << "file can not be opened" << std::endl;
}


