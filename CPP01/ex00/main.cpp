#include "Zombie.hpp"

int	main()
{
	Zombie	*heap_zombie;

	heap_zombie = newZombie("Zombla");
	heap_zombie->announce();
	delete heap_zombie;

	std::cout << std::endl << "******************************" 
		<<std::endl << std::endl;
	
	randomChump("Shambite");
	
	return (0);
}
