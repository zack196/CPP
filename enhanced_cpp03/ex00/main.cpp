#include "ClapTrap.hpp"

int main()
{
    ClapTrap    ct("clap1");
    
    ct.attack("an_other_one");
    ct.beRepaired(2);
    ct.takeDamage(2);
}