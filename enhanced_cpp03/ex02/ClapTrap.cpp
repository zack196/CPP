#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default_ct"), hit_point(10), energy_point(10)
    , attack_damage(0)
{
    std::cout << "ClapTrap " << name << " constructed by default constructor!" 
        << std::endl;
}

ClapTrap::ClapTrap(std::string ct_name) : name(ct_name), hit_point(10)
    , energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " constructed by named constructor!" 
        << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    name = src.name;
    hit_point = src.hit_point;
    energy_point = src.energy_point;
    attack_damage = src.attack_damage;
    std::cout << "ClapTrap " << name << " constructed by copy constructor!" 
        << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name <<" has been destructed!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap named " << rhs.name << " has been assigned to"
		<<" ClapTrap named " << this->name << "!" << std::endl;
	if (this != &rhs)
	{
		name = rhs.name;
		hit_point = rhs.hit_point;
		energy_point = rhs.energy_point;
		attack_damage = rhs.attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (!hit_point)
		std::cout << "ClapTrap have no hit point left!" << std::endl;
	if (!energy_point)
	{
		std::cout << "ClapTrap have no energy left!" << std::endl;
		return ;
	}
	energy_point--;
	std::cout << "ClapTrap " << name << " attacks " <<target << ", causing " 
		<< attack_damage <<" points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hit_point)
	{
	    std::cout << "ClapTrap have no hit point left!" << std::endl;
	    return ;
	}
	unsigned int damage = (amount < hit_point) ? amount : hit_point;
	hit_point -= damage;
	std::cout << "ClapTrap " << name << " takes " << damage
	  << " points of damage! Hit points left: " << hit_point << std::endl;
	if (!hit_point)
	    std::cout << "ClapTrap " << name << "has been defeated!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hit_point)
	    std::cout << "ClapTrap have no hit point left!" << std::endl;
	if (!energy_point)
	{
	    std::cout << "ClapTrap have no energy left!" << std::endl;
	    return ;
	}
	energy_point--;
	hit_point += amount;
	std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount 
		<< " hit points! Current hit points: " << hit_point
		<< ", energy points left: " << energy_point << std::endl;
}
