#include "BitcoinExchange.hpp"

map	fill_map(const string &dataBase)
{
	fstream	file;
	string	line;
	map		ret;
	string	date;

	file.open(dataBase.c_str(), std::ios::in);
	if (file.is_open())
	{
		getline(file, line);
		while (getline(file, line))
		{
			date = line.substr(0, 10);
			ret[date] = std::strtod( line.substr(11, line.size()).c_str() , NULL);
		}
	}
	else
		std::cerr << "can't open data.csv\n";
	return ret;
}

std::pair<string, double> get_data(string line)
{
	string		date;
	double		value;
	struct tm	t;
	time_t		time;
	char		*end;
	
	date = line.substr(0, 10);
	t.tm_year = std::atoi(line.substr(0, 4).c_str()) - 1900;
	t.tm_mon = std::atoi(line.substr(5, 2).c_str()) - 1;
	t.tm_mday = std::atoi(line.substr(8, 2).c_str());
	time = std::mktime(&t);
	if (time == (time_t)-1)
		throw(BadInputTime());
	if (line.size() < 12)
		throw(BadValue());
	value = std::strtod(line.substr(12, line.size()).c_str(), &end);
	if (end)
		throw(BadValue());
	if (value < 0)
		throw(Negative());
	if (value > 1000)
		throw(LargeNumber());
	return std::make_pair(date, value);
}
