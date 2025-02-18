#include "BitcoinExchange.hpp"

int	main(int ac , char **av)
{
	if (ac == 2)
	{
		string	line;
		fstream	file;
		map		m;
		
		file.open(av[1], std::ios::in);
		if (file.is_open())
		{
			std::pair<string, double>	data;

			m = fill_map("data.csv");
			map::iterator	it;
			map::iterator	pit = m.begin();
			getline(file, line);
			while (getline(file, line))
			{
				try
				{
					data = get_data(line);

					it = m.begin();
					while ( it != m.end() && it->first.compare(data.first.c_str()) < 0 )
					{
						pit = it;
						it++;
					}
					std::cout << data.first << " => " << data.second << " = " 
						<< pit->second * data.second << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cerr << "" << '\n';
				}
			}
		}
		else
			std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	std::cerr << "Error: could not open file.\n";
	return 1;
}
