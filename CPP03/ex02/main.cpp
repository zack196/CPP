#include "FragTrap.hpp"

int main()
{
    FragTrap    f("hakona");
    std::cout << "**********************************" << std::endl;

    f.attack("matata");
    f.takeDamage(20);
    f.beRepaired(13);
    f.takeDamage(100);
    f.highFivesGuys();
    std::cout << "**********************************" << std::endl;
    f.attack("matata");
    f.takeDamage(20);
    f.beRepaired(13);
    std::cout << "**********************************" << std::endl;
    FragTrap    copy_f(f);
    std::cout << "**********************************" << std::endl;
    FragTrap    as_f;
    std::cout << "**********************************" << std::endl;
    as_f = copy_f;
    std::cout << "**********************************" << std::endl;
}
