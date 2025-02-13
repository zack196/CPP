# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->name = "FT";
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << "Default constructor of FragTrap!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    this->name = src.name;
    this->hit_point = src.hit_point;
    this->energy_point = src.energy_point;
    this->attack_damage = src.attack_damage;
    std::cout << "copy constructor of FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string f_name) : ClapTrap(f_name)
{
    name = f_name;
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << "named constructor of FragTrap!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap has been destructed!" <<std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& rhs)
{
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hit_point = rhs.hit_point;
        this->energy_point = rhs.energy_point;
        this->attack_damage = rhs.attack_damage;
    }
    std::cout << "assingment operator FragTrap!" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " : High Fives Guys!!" << std::endl;
}
