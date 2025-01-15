#include "ScavTrap.hpp"

int main()
{
    ScavTrap st1("alpha");

    st1.attack("other_one");
    
    st1.beRepaired(1);
    st1.takeDamage(9);
    st1.guardGate();
    return 0;
}