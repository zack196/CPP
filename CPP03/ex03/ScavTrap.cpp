# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	name = "ST";
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "Default constructor of ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string s_name) : ClapTrap(s_name)
{
	name = s_name;
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "named constructor of ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	this->name = src.name;
	this->hit_point = src.hit_point;
	this->energy_point = src.energy_point;
	this->attack_damage = src.attack_damage;
	std::cout << "copy constructor of ScavTrap!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap has been destructed!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->energy_point)
	{
		std::cout << "ScavTrap " << this->name << " have no energy point left!" << std::endl;
		return ;
	}
	if (!this->hit_point)
	{
		std::cout << "ScavTrap " << this->name << " have no hit point left!" << std::endl;
		return ;
	}
	this->energy_point--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " , causing "
		<< this->attack_damage <<" points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hit_point = rhs.hit_point;
		this->energy_point = rhs.energy_point;
		this->attack_damage = rhs.attack_damage;
	}
	std::cout << "assingment operator ScavTrap!" << std::endl;
	return *this;
}
