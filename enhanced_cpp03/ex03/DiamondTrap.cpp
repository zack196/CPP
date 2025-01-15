#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    this->name = "default_dt";
    ClapTrap::name = this->name + "_clap_name";
    hit_point = FragTrap::hit_point;
    energy_point = ScavTrap::energy_point;
    attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap " << name << " constructed by default constructor!" 
        << std::endl;
}


DiamondTrap::DiamondTrap(std::string _name) :  ClapTrap(_name + "_clap_name")
    , FragTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name")
{
    this->name = _name;
    ClapTrap::name = this->name + "_clap_name";
    hit_point = FragTrap::hit_point;
    energy_point = ScavTrap::energy_point;
    attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap " << ClapTrap::name << " constructed by named" 
        <<" constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src)
, ScavTrap(src), name(src.name)
{
    std::cout << "DiamondTrap " << this->name << " constructed by copy constructor!" 
        << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " has been destructed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " and my Claptrap name is " 
        << ClapTrap::name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
