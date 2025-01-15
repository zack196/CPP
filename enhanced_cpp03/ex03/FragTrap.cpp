#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    name = "default_ft";
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " constructed by default constructor!" 
        << std::endl;
}

FragTrap::FragTrap(std::string ft_name) : ClapTrap(ft_name)
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " constructed by named constructor!" 
        << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap " << name << " constructed by copy constructor!" 
        << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " has been destrocted!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (!hit_point)
		std::cout << "FragTrap have no hit point left!" << std::endl;
	if (!energy_point)
	{
		std::cout << "FragTrap have no energy left!" << std::endl;
		return ;
	}
	energy_point--;
	std::cout << "FragTrap " << name << " attacks " <<target << ", causing " 
		<< attack_damage <<" points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap "<< name <<" says: High five!!" << std::endl;
}