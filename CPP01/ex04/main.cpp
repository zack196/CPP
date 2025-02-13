#include <iostream>
#include <fstream>
#include <string>

std::string	remplace_in_line(std::string line, std::string s1, std::string s2)
{
	size_t	pos;

	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1);
	}
	return line;
}

void	err_msg(std::string file)
{
	std::cerr << "Error openning the " << file << " file!" << std::endl;
	if (errno == ENOENT) 
        std::cerr << "Error: File does not exist." << std::endl;
    else if (errno == EACCES) 
        std::cerr << "Error: Permission denied." << std::endl;
}

void	ft_remplace(std::string file_name, std::string s1, std::string s2)
{
	std::ifstream	file_in;

	file_in.open(file_name.c_str(), std::ios::in);
	if (file_in.is_open())
	{
		std::string		out_file_name;
		std::ofstream	file_out;

		out_file_name = file_name + ".replace";
		file_out.open(out_file_name.c_str(), std::ios::out);
		if (file_out.is_open())
		{
			std::string	line;
			while (getline(file_in, line))
			{
				line = remplace_in_line(line, s1, s2);
				file_out << line << std::endl;
			}
			file_out.close();
		}
		else
			err_msg(out_file_name);
		file_in.close();
	}
	else
		err_msg(file_name);
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		ft_remplace(av[1], av[2], av[3]);
		return 0;
	}
	std::cout << "not enough argument!" << std::endl;
	return (1);
}