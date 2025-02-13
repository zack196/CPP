#include "HumanB.hpp"

HumanB::HumanB(std::string name_b) : name(name_b), weapon(NULL) {}

HumanB::~HumanB() 
{
	std::cout << "Human B destryed!" << std::endl;
}

void	HumanB::attack() 
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name <<"'s weapon is NULL ptr!" << std::endl;
}

void	HumanB::setWeapon( Weapon & w)
{
	weapon = &w;
}

