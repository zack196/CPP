/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:53:44 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/16 17:37:33 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_hpp
# define Zombie_hpp

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(std::string z_name);
	~Zombie();
	Zombie();
	void announce( void );
};


Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif