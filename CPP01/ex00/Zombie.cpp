/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:53:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/11 20:31:55 by zel-oirg         ###   ########.fr       */
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
    std::cout << name << " has been destroyed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie( std::string name )
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	return (new_zombie);
}

void randomChump(std::string name)
{
	Zombie	zomb(name);

	zomb.announce();
}
