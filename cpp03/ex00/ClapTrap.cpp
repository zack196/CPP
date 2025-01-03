#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout <<"Default constructor is called. ClapTrap need a name!!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_point(10)
	, energy_point(10), attack_damage(0) 
{
	std::cout << "ClapTrap named " << name << " has been constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	name = src.name;
	hit_point = src.hit_point;
	energy_point = src.energy_point;
	attack_damage = src.attack_damage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destractor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->energy_point = rhs.energy_point;
		this->hit_point = rhs.hit_point;
		this->attack_damage = rhs.attack_damage;
	}
	return (*this);
}


/*Geters And Seters*/

std::string		ClapTrap::get_name()
{
	return name;
}

unsigned int	ClapTrap::get_hit_point()
{
	return hit_point;
}

unsigned int	ClapTrap::get_energy()
{
	return energy_point;
}

unsigned int	ClapTrap::get_attack_damage()
{
	return attack_damage;
}

void	ClapTrap::set_name(std::string name)
{
	this->name = name;
}

void	ClapTrap::set_hit_point(unsigned int hit_point)
{
	this->hit_point = hit_point;
}

void	ClapTrap::set_energy(unsigned int energy)
{
	this->energy_point = energy;
}

void	ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	this->attack_damage = attack_damage;
}

void ClapTrap::attack(const std::string& target)
{
	if (energy_point)
	{
		if (hit_point)
		{
			energy_point--;
			std::cout << "ClapTrap " << name << " attacks " << target 
				<<", causing " << attack_damage <<" points of damage!\n";
			return ;
		}
		std::cout << "ClapTrap " << name << " have no hit point left!" << std::endl;
	}
	std::cout << "ClapTrap " << name << " run out of energy it can not attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point)
	{
		if (hit_point > amount)
		{
			hit_point -= amount;
			std::cout << "ClapTrap " << name << " took " << amount << " damage!" 
				<< " and have " << hit_point <<" left." << std::endl; 
		}
		else
		{
			hit_point = 0;
			std::cout << "ClapTrap " << name << " took " << amount << " damage!" 
				<< " and have no hit point left" << std::endl; 
		}
		return ;
	}
	std::cout << "ClapTrap " << name << " have no hit point left!" <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point)
	{
		if (energy_point)
		{

			energy_point--;
			hit_point += amount;
			std::cout << "ClapTrap " << name << " is reparing it self, it gain "
				<< amount << " hit point back" << "it have " << hit_point 
				<< " hit_point" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << name 
				<< " run out of energy, it can not be repared!" << std::endl; 
		}
		return ;
	}
	std::cout << "ClapTrap " << name << " have no hit point left!" <<std::endl;
}
