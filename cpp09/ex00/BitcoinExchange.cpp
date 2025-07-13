#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& fileInput, std::map<std::string, float> dataBase) : _dataBase(dataBase), _fileInput(fileInput)
        {
            // _dataBase = getCsvData("data.csv");
            std::ifstream   file(fileInput.c_str());
            if (file.is_open())
            {
                std::string line;
                // ignore the first line
                getline(file, line);
                while (getline(file, line))
                {
                    try
                    {
                        size_t  slashPos = line.find("|");
                        if (slashPos == std::string::npos)
                            throw(std::runtime_error("Error: bad input => " + line));

                        std::string date = line.substr(0, slashPos);
                        date = validateDate(date);

                        std::string amountStr = line.substr(slashPos + 1);
                        float amount = validateAmount(amountStr);

                        float val = getValue(date, _dataBase);

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
    std::string date = trimspaces(str);
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

float BitcoinExchange::validateAmount(const std::string& str)
{
    float   x;
    int     tmp;
    int     nbr_point = 1;

    std::string amount = trimspaces(str);
    std::istringstream  ss(amount);

    for (size_t i = 0; i < amount.size(); i++)
    {
        if (i == 0 && amount[i] == '-')
            continue ;
        if (!std::isdigit(amount[i]) && amount[i] != '.')
            throw(std::runtime_error("Error: bad input => number " + amount));
        if (amount[i] == '.' && !nbr_point--)
            throw(std::runtime_error("Error two point"));
    }
    
    if (nbr_point == 1)
    {
        ss >> tmp;
        if (tmp < 0)
        throw(std::runtime_error("Error: not a positive number."));
        else if (tmp > 1000)
        throw(std::runtime_error("Error: too large a number."));
        return (static_cast<float>(tmp));
    }
    ss >> x;
    if (x < 0)
        throw(std::runtime_error("Error: not a positive number."));
    else if (x > 1000)
        throw(std::runtime_error("Error: too large a number."));

    return x;
}

float BitcoinExchange::getValue(std::string date, std::map<std::string, float> dataBase)
{
    std::map<std::string, float>::iterator prevIt = dataBase.begin();
    std::map<std::string, float>::iterator it = dataBase.begin();
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
{
    _dataBase = cp._dataBase;
    _fileInput = cp._fileInput;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
    _dataBase = rhs._dataBase;
    _fileInput = rhs._fileInput;
    return *this;
}