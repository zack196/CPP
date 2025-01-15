#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt;

    std::cout <<"\n\n";
    DiamondTrap d(dt);
    std::cout <<"\n\n";
    

    d.beRepaired(2);
    d.attack("monster");
    d.guardGate();
    d.highFivesGuys();
    std::cout <<"\n\n";


    return 0;
}