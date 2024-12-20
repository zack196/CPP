#include <iostream>

static char	to_uper(char c)
{
	if ('a' <= c && c <= 'z')
    	return (c + 'A' - 'a');
	return (c);
}

static void	megaphone(char *str)
{
    int i;

	i = -1;
	while (str[++i])
		std::cout << to_uper(str[i]);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[i])
	{
		megaphone(av[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
