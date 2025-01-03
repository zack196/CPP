#ifndef Clap_Trap_hpp
#define Clap_Trap_hpp

#include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hit_point;
	unsigned int	energy_point;
	unsigned int	attack_damage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);

    ~ClapTrap();
	ClapTrap&	operator=(const ClapTrap &rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	/*Geters And Seters*/
	std::string		get_name();
	unsigned int	get_hit_point();
	unsigned int	get_energy();
	unsigned int	get_attack_damage();

	void	set_name(std::string name);
	void	set_hit_point(unsigned int hit_point);
	void	set_energy(unsigned int energy);
	void	set_attack_damage(unsigned int attack_damage);
};



#endif