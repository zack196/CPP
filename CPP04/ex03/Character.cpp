#include "Character.hpp"

Character::Character()
{
	_name = "";
	for (int i = 0; i < 4; i++)
		inven[i] = NULL;
}

Character::Character(const Character &copy)
{
	_name = copy._name;
	for (int i = 0; i < 4; i++)
		inven[i] = (copy.inven[i]) ? copy.inven[i]->clone() : NULL ;
}

Character::Character(const std::string &name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		inven[i] = NULL;
}

Character&	Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			delete inven[i];
			inven[i] = (rhs.inven[i])? rhs.inven[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character() {}

std::string const & Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inven[i] == NULL)
		{
			inven[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (!(0 <= idx && idx < 4) || !inven[idx])
		return ;
	inven[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx < 4 && inven[idx])
		inven[idx]->use(target);
}
