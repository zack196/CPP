#ifndef HumanA_hpp
# define HumanA_hpp

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
    std::string	name;
	Weapon&		weapon;
public:
	HumanA(std::string name_a,  Weapon& Weapon_a);
	~HumanA();

	void	attack();
};



#endif