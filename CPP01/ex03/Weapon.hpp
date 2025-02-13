#ifndef Weapon_hpp
# define Weapon_hpp

# include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string w_type);
	~Weapon();

	void					setType(std::string w_type);
	const std::string&		getType() const;
};



#endif