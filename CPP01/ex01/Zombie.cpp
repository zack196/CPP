/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:53:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/16 17:30:54 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string z_name) : name(z_name)
{
	std::cout << "Zombie named " << name << " was created!" << std::endl;
}

Zombie::Zombie()
{
	std::cout << "default Zombie object was constructed" << std::endl;
	name = "Def Zombie";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string z_name)
{
	name = z_name;
}

Zombie* newZombie( std::string name )
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	
	return (new_zombie);
}

void randomChump( std::string name )
{
	Zombie	zomb(name);

	zomb.announce(); 
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombie_horde;

	if (N <= 0)
	{
		std::cout << "the number of zombies shoud be positive" << std::endl;
		return NULL;
	}
	zombie_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie_horde[i].set_name(name);
	return (zombie_horde);
}
