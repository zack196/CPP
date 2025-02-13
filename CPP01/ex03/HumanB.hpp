#ifndef HumanB_hpp
# define HumanB_hpp

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
    std::string	name;
	Weapon		*weapon;
public:
	HumanB(std::string name_b);
	~HumanB();
	void	setWeapon( Weapon & w);

	void	attack();
};



#endif