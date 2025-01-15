#ifndef FragTrap_hpp
#define FragTrap_hpp

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &src);
    ~FragTrap();

    void highFivesGuys(void);
    void attack(const std::string& target);
};



#endif