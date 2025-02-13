#include "Zombie.hpp"

int main()
{
	Zombie	*zombies;
	int		N = 8;

	zombies = zombieHorde(N, "zombla");
	for (int i = 0; i < N; i++)
		zombies->announce();
	delete [] zombies;


	std::cout << "***************************" << std::endl; 
	N = -8;

	zombies = zombieHorde(N, "zombla");
	for (int i = 0; i < N; i++)
		zombies->announce();
	delete [] zombies;

	std::cout << "***************************" << std::endl; 
	N = 1;

	zombies = zombieHorde(N, "zombla");
	for (int i = 0; i < N; i++)
		zombies->announce();
	delete [] zombies;

	return (0);
}
