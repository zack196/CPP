# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = "DT";
	ClapTrap::name += "_clap_name";
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Default constructor of DiamondTrap!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string d_name) : ClapTrap(d_name), ScavTrap(d_name), FragTrap(d_name)
{
	this->name = d_name;
	ClapTrap::name += "_clap_name";
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "named constructor of DiamondTrap!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src ) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "copy constructor of DiamondTrap!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap has been destructed!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		this->::ClapTrap::name = rhs.ClapTrap::name;
		this->name = rhs.name;
		this->hit_point = rhs.hit_point;
		this->energy_point = rhs.energy_point;
		this->attack_damage = rhs.attack_damage;
	}
	return *this ;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name :" << this->name << " ,and ClapTrap name : " 
		<< this->ClapTrap::name  << std::endl;
}
