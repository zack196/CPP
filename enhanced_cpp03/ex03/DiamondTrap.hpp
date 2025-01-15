#ifndef DiamondTrap_hpp
#define DiamondTrap_hpp

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string    name;
public:
    DiamondTrap();
    DiamondTrap(std::string _name);
    DiamondTrap(const DiamondTrap &rhs);
    ~DiamondTrap();

    void whoAmI();
    void attack(const std::string& target);
};



#endif