#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    name = "default_st";
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " constructed by default constructor!" 
        << std::endl;
}

ScavTrap::ScavTrap(std::string st_name) : ClapTrap(st_name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " constructed by named constructor!" 
        << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap " << name << " constructed by copy constructor!" 
        << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been destrocted!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (!hit_point)
		std::cout << "ScavTrap have no hit point left!" << std::endl;
	if (!energy_point)
	{
		std::cout << "ScavTrap have no energy left!" << std::endl;
		return ;
	}
	energy_point--;
	std::cout << "ScavTrap " << name << " attacks " <<target << ", causing " 
		<< attack_damage <<" points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name <<" has entered Gatekeeper mode." 
        << std::endl;
}
