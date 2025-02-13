#ifndef ScavTrap_hpp
#define ScavTrap_hpp

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
    
public:
    ScavTrap();
    ScavTrap(std::string s_name);
    ScavTrap(const ScavTrap &src);
    ~ScavTrap();
    ScavTrap&   operator=(const ScavTrap &rhs);
    void	attack(const std::string& target);
    void    guardGate();
};

#endif