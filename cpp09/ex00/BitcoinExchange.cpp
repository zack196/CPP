#include "BitcoinExchange.hpp"

/*
2011-01-03 | 
2011-01-03 | -
2011-01-03 |1  //no space
2011-01-03  1432432 | 2
2009-01-02 | 2147483647
2022-03-1.1 | 1000


parse line 1 and it should be == date | value

*/

BitcoinExchange::BitcoinExchange(const std::string& fileInput, std::map<std::string, double> dataBase) : _dataBase(dataBase), _fileInput(fileInput)
        {
            std::ifstream   file(fileInput.c_str());
            if (file.is_open())
            {
                std::string line;
                // ignore the first line
                getline(file, line);
                if (line != "date | value")
                    throw(std::runtime_error("\"date | value\" should be on the top of the file"));
                while (getline(file, line))
                {
                    try
                    {
                        size_t  slashPos = line.find(" | ");
                        if (slashPos == std::string::npos)
                            throw(std::runtime_error("Error: bad input => " + line));

                        std::string date = line.substr(0, slashPos);
                        date = validateDate(date);

                        if (line.size() <= slashPos + 3) throw(std::runtime_error("Error: bad input => " + line));
                        std::string amountStr = line.substr(slashPos + 3); // here were it crach the (2025-02-11 |) exemple
                        double amount = validateAmount(amountStr);

                        double val = getValue(date, _dataBase);

                        std::cout << date << " => " << amount << " = " << amount * val << std::endl;
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
            }
            else
                throw(std::runtime_error("error opnning the file : " + std::string(fileInput)));
        }

BitcoinExchange::~BitcoinExchange() {}



std::string trimspaces(const std::string& str)
{
    size_t begin = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return str.substr(begin, end - begin + 1);
}

std::string BitcoinExchange::validateDate(const std::string& str)
{
    std::string date = str;//trimspaces(str);
    int dash_count = 0;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (date[i] == '-')
            dash_count++;
        if (dash_count > 2 || (date[i] != '-' && !isdigit(date[i])))
            throw(std::runtime_error("Error: bad input date => " + str));
        
    }
    
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);

    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        throw(std::runtime_error("Error: bad input date => " + str));
    
    if (dash1 != '-' || dash2 != '-')
        throw(std::runtime_error("Error: bad input date => " + str));

    if (year < 1 || month < 1 || month > 12 || day < 1)
        throw(std::runtime_error("Error: bad input date => " + str));

    int nmbrDaysInMounth [] = {0, 31, 28, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) )
    {
        if (day > 29)
            throw(std::runtime_error("Error: bad input date => " + str));
        }
    else
    {
        if (day > nmbrDaysInMounth[month])
            throw(std::runtime_error("Error: bad input date => " + str));
    }
    return date;
}

bool no_digit(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            return false;
    }
    return true;
}

bool two_point(const std::string& str)
{
    int nbr_pnt = 0;
    for (size_t i = 0; i < str.size(); i++)
    if (str[i] == '.')
        nbr_pnt++;
    return nbr_pnt > 1 ;
}

bool check_digits(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
        {
            if (str[i] == '-')
                throw(std::runtime_error("Error: not a positive number."));
            continue;
        }
        if (!isdigit(str[i]) && str[i] != '.') 
            return true;
    }
    return false;
}

double BitcoinExchange::validateAmount(const std::string& str)
{
    std::string amount = str;

    if (no_digit(amount) || two_point(amount) || check_digits(amount))
        throw(std::runtime_error("Error: bad input => number " + amount));
        
    std::istringstream ss(amount);
    double res;
    ss >> res;
    if (res > 1000)
        throw(std::runtime_error("Error: too large a number."));
    
    return res;
}

double BitcoinExchange::getValue(std::string date, std::map<std::string, double> dataBase)
{
    std::map<std::string, double>::iterator prevIt = dataBase.begin();
    std::map<std::string, double>::iterator it = dataBase.begin();
    if (date < it->first)
        throw(std::runtime_error("Error: our data begin from 2009-01-02"));
    
    for (it = dataBase.begin(); it != dataBase.end(); it++)
    {
        if (it->first > date)
            return prevIt->second;
        prevIt = it;
    }
    return prevIt->second;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cp) 
    : _dataBase(cp._dataBase), _fileInput(cp._fileInput) {}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
    if (this != &rhs)
    {
        _dataBase = rhs._dataBase;
        _fileInput = rhs._fileInput;
    }
    return *this;
}