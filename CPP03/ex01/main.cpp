#include "ScavTrap.hpp"

int main()
{
    ScavTrap    s1("Oscar");
    std::cout << "**************************" << std::endl;

    s1.attack("Oscar");
    s1.guardGate();
    std::cout << "**************************" << std::endl;
    s1.takeDamage(12);
    s1.beRepaired(7);
    std::cout << "**************************" << std::endl;



}