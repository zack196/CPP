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
			ret[date] = strtod( line.substr(11, line.size()).c_str() , NULL);
		}
	}
	else
		std::cerr << "can't open data.csv\n";
	return ret;
}

bool isValidDate(int year, int month, int day) {
    struct tm t = {};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;

    time_t time = mktime(&t);
    return (time != (time_t)-1) && (t.tm_mday == day);
}

std::pair<string, double>	get_data(string line)
{
	int year = atoi(line.substr(0, 4).c_str());
	int month = atoi(line.substr(5, 2).c_str());
	int day = atoi(line.substr(8, 2).c_str());

	if (!isValidDate(year, month, day))
		throw(std::runtime_error(("Error: bad input => " + line).c_str()));
	if (line.size() < 12)
		throw(std::runtime_error(("Error: bad input => " + line).c_str()));
	
	string		date = line.substr(0, 10);

	char		*end;
	double		value = strtod(line.substr(12, line.size()).c_str(), &end);

	if (*end)
		throw(std::runtime_error("Error: value"));

	if (value < 0)
		throw(std::runtime_error("Error: not a positive number."));

	if (value > 1000)
		throw(std::runtime_error("Error: too large a number."));

	return std::make_pair(date, value);
}
