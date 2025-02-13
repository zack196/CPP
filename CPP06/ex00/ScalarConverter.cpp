#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) 
{
	(void) copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void) rhs;
	return *this;
}

int identify_type(std::string type_id)
{
    if (type_id == "nan" || type_id == "inf" || type_id == "-inf")
        return 4;
    if (type_id == "nanf" || type_id == "inff" || type_id == "-inff")
        return 3;
    if ((type_id.size() == 1 && !isdigit(type_id[0])))
        return 1;
    
    int i = 0;
    int is_decimal = 0;
    while (type_id[i])
    {
        if (type_id[0] == '+' || type_id[0] == '-')
            type_id.erase(0, 1);
        if (!isdigit ( static_cast<int> (type_id[i]) ))
        {
            if (type_id[i] == '.' && is_decimal == 0)
            {
                is_decimal = 1;
                i++;
                if (!type_id[i])
                    return 4;
                if (type_id[i] == 'f')
                    return 3;
            }
            else if (type_id[i] == 'f' && !type_id[i + 1])
                return 3;
            else 
                return 5;
        }
        i++;
    }
    if (is_decimal == 1)
        return 4;
    return 2;
}

void print_char(std::string input)
{
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
        
    std::cout << "int: " << static_cast<int>(c) << std::endl;
        
    std::cout << "float: " << std::fixed << std::setprecision(1) 
            << static_cast<float>(c) << "f" << std::endl;
        
    std::cout << "double: " << std::fixed << std::setprecision(1) 
        << static_cast<double>(c) << std::endl;
}

int ft_atoi(std::string nbr)
{
    long    res = 0;
    int     sign = 1;
    int     i = 0;

    if (nbr[i] == '-' || nbr[i] == '+')
        if (nbr[i++] == '-')
            sign = -1;
    while (isdigit(nbr[i]) && res <= INT_MAX)
    {
        res = 10 * res + (nbr[i] - '0');
        i++;
    }
    if (res > INT_MAX)
        throw(std::logic_error("overflow"));
    return res * sign ;
}

void print_int(std::string input)
{
    try
    {
        int val_int = ft_atoi(input);

        if ( !(0 <= val_int && val_int <= 255) )
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(val_int))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(val_int) << "'" << std::endl;

        std::cout << "int: " << val_int << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) 
            << static_cast<float>(val_int) << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) 
            << static_cast<double>(val_int) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Number too big the int overfloed!" << std::endl;
    }
}

void print_float(std::string input)
{
	float f = std::atof(input.c_str());

	// char
    if ( !(0 <= f && f <= 255) )
	{
        std::cout << "char: impossible" << std::endl;
	}
    else if (!isprint(static_cast<int>(f)))
    {
	    std::cout << "char: Non displayable" << std::endl;
	}
    else
	{
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}

	//int
	if (static_cast<float> (INT_MIN) <= f && f <= static_cast<float>(INT_MAX) )
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	//float
	if (f == std::floor(f))
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	//double
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	print_double(std::string input)
{
	double	d;
	
	d = std::strtod(input.c_str(), NULL);
	if ( !(0 <= d && d <= 255) )
	{
        std::cout << "char: impossible" << std::endl;
	}
    else if (!isprint(static_cast<int>(d)))
    {
	    std::cout << "char: Non displayable" << std::endl;
	}
    else
	{
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}

	//int
	if (static_cast<float> (INT_MIN) <= d && d <= static_cast<float>(INT_MAX) )
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
    //float and double
	if (d == std::floor(d))
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return ;
	}
	std::cout << "float: " << static_cast<float>(d) << "f" <<std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
    int i = identify_type(input);
    if (i == 1)
        print_char(input);
    else if (i == 2)
        print_int(input);
    else if (i == 3)
        print_float(input);
    else if (i == 4)
        print_double(input);
    else if (i == 5)
        std::cout << "error" << std::endl;
}

