#ifndef FragTrap_cpp
#define FragTrap_cpp

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    
public:
    FragTrap();
    FragTrap(const FragTrap &src);
    FragTrap(std::string f_name);
    ~FragTrap();

    FragTrap&   operator=(const FragTrap& rhs);
    void highFivesGuys(void);
};


#endif