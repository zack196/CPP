#include "ClapTrap.hpp"

int main()
{
    ClapTrap    c1;
    ClapTrap    c2("super");

    c1.attack("super");
    c2.takeDamage(3);
    c2.beRepaired(2);
    c1.takeDamage(20);
    c2.takeDamage(9);


    c1.takeDamage(1);
    c1.beRepaired(40);
    c1.attack("supper");

    c2.takeDamage(1);
    c2.beRepaired(40);
    c2.attack("supper");

    c1 = c2;
}