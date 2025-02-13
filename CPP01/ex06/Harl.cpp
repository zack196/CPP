#include "Harl.hpp"

void Harl::complain( complaining level )
{
	switch (level)
	{
		case DEBUG : 
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
			info();
			warning();
			error();
			break;
		case INFO :
			std::cout << "[ INFO ]" << std::endl;
			info();
			warning();
			error();
			break ;
		case WARNING :
			std::cout << "[ WARNING ]" << std::endl;
			warning();
			error();
			break;
		case ERROR :
			std::cout << "[ ERROR ]" << std::endl;
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-"
        <<"cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money." 
        <<" You didn't put enough bacon in my burger! If you did,"
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
    std::cout << "This is unacceptable! I want to speak to the "
        <<"manager now." << std::endl;
}


Harl::Harl(){}
Harl::~Harl(){}