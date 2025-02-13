# include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap    d("hakona");
	std::cout << "**********************************" << std::endl;

	d.attack("matata");
	d.takeDamage(20);
	d.beRepaired(13);
	d.takeDamage(100);
	d.highFivesGuys();
	d.guardGate();
	std::cout << "**********************************" << std::endl;
	d.attack("matata");
	d.takeDamage(20);
	d.beRepaired(13);
	std::cout << "**********************************" << std::endl;
	DiamondTrap    copy_d(d);
	std::cout << "**********************************" << std::endl;

	std::cout << "**********************************" << std::endl;
	DiamondTrap    as_d;
	std::cout << "**********************************" << std::endl;
	as_d = copy_d;
	as_d.whoAmI();
	std::cout << "**********************************" << std::endl;
}
