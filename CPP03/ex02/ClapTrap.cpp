#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "CT";
    hit_point = 10;
    energy_point = 10;
    attack_damage = 0;
    std::cout << "Default constructor of ClapTrap!" << std::endl;
}

ClapTrap::ClapTrap( std::string c_name)
{
	name = c_name;
    hit_point = 10;
    energy_point = 10;
    attack_damage = 0;
    std::cout << "named constructor of ClapTrap!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    this->name = src.name;
    this->hit_point = src.hit_point;
    this->energy_point = src.energy_point;
    this->attack_damage = src.attack_damage;
    std::cout << "copy constructor of ClapTrap!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap has been destructed!" <<std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hit_point = rhs.hit_point;
        this->energy_point = rhs.energy_point;
        this->attack_damage = rhs.attack_damage;
    }
    std::cout << "assingment operator ClapTrap!" << std::endl;
    return *this;
}

void	ClapTrap::attack(const std::string& target)
{
    if (!this->energy_point)
    {
        std::cout << "ClapTrap " << this->name << " have no energy point left!" << std::endl;
        return ;
    }
    if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " have no hit point left!" << std::endl;
        return ;
    }
    this->energy_point--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << " , causing "
        << this->attack_damage <<" points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->energy_point)
    {
        std::cout << "ClapTrap " << this->name << " have no energy point left!" << std::endl;
        return ;
    }
    if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " have no hit point left!" << std::endl;
        return ;
    }
    unsigned int    damage;
    
    damage = (amount > this->hit_point) ?  this->hit_point : amount;
    this->hit_point -= damage;
	std::cout << "ClapTrap " << this->name << " take " << damage << " point amount of damage" 
		<< std::endl;
	if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " has been defeated!" << std::endl;
        return ;
    }
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energy_point)
    {
        std::cout << "ClapTrap " << this->name << " have no energy point left!" << std::endl;
        return ;
    }
    if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " have no hit point left!" << std::endl;
        return ;
    }
	this->energy_point--;
	this->hit_point += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself, it gets " << amount 
		<< " hit points back." << std::endl;
}

