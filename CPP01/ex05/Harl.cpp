#include "Harl.hpp"

void Harl::complain( std::string level )
{
    int complain_level;

    fct harl_fct [] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    complain_level = 1 * (level == "DEBUG") + 2 * (level == "INFO")
        + 3 * (level == "WARNING") + 4 * (level == "ERROR") - 1;
    if (complain_level == -1)
    {
        std::cout << level <<"is not availible, [DEBUG], [INFO], [WARNING], [ERROR]"
            << std::endl;
        return ;
    }
    Harl    harl;
    (harl.*harl_fct[complain_level])();
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle"
        <<"-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put " 
        << "enough bacon in my burger! If you did,"
        <<" I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free." 
        << " I’ve been coming for years whereas you "
        <<"started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(){}
Harl::~Harl(){}