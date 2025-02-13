#ifndef ClapTrap_hpp
# define ClapTrap_hpp

#include <iostream>

class ClapTrap
{
protected :
    std::string		name;
    unsigned int	hit_point;
    unsigned int	energy_point;
    unsigned int	attack_damage;
public:
	ClapTrap();
	ClapTrap( std::string c_name);
	ClapTrap(const ClapTrap &src);
	virtual ~ClapTrap();
	ClapTrap&	operator=(const ClapTrap &rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif