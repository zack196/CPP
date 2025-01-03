#include "ClapTrap.hpp"

int main()
{
    ClapTrap    ct1("sindid");

    ct1.attack("rama7");
    // ct1.takeDamage(2);
    ct1.set_energy(0);
    ct1.attack("rama7");
    ct1.takeDamage(2);
    ct1.beRepaired(3);
    
    return 0;
}