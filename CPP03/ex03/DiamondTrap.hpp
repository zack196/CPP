#ifndef DiamondTrap_hpp
# define DiamondTrap_hpp

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    std::string name;
    using ScavTrap::name;
public:
    DiamondTrap();
    DiamondTrap(std::string d_name);
    DiamondTrap(const DiamondTrap &src );
    ~DiamondTrap();

    DiamondTrap&    operator=(const DiamondTrap &rhs);
    void whoAmI();
};

#endif