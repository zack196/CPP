# include "HumanA.hpp"

HumanA::HumanA(std::string name_a,  Weapon& weapon_a) : name(name_a), weapon(weapon_a){}

HumanA::~HumanA() 
{
	std::cout << "Human A destryed!" << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
