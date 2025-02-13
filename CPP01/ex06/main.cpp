#include "Harl.hpp"

complaining	get_complining_level(std::string level)
{
	int	l;

	l = (DEBUG * (level == "DEBUG") + INFO * (level == "INFO") 
		+ WARNING * (level == "WARNING") + ERROR * (level == "ERROR"));
	switch (l)
	{
		case 1 : return (DEBUG); break;
		case 2 : return (INFO); break;
		case 3 : return (WARNING); break;
		case 4 : return (ERROR); break;
		default: return (NOT_RELEVENT); break;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string	level;
		complaining	max_level;
		Harl		harl;

		level = av[1];
		max_level = get_complining_level(level);
		harl.complain(max_level);
		return 0;
	}
	std::cout << "you shoud enter one parametre to the program!" << std::endl;
	return 1;
}