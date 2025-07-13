#include "BitcoinExchange.hpp"

std::map<std::string, float> getCsvData(const std::string& dataCsv)
{
    std::map<std::string, float> csvDataMap;
    std::ifstream   file(dataCsv.c_str());
    if (file.is_open())
    {
        std::string line;
        // ignor the first line   date,exchange_rate
        getline(file, line);
        while (getline(file, line))
        {
            size_t commaPos = line.find(",");
            std::string date = line.substr(0, commaPos);
            std::string value = line.substr(commaPos + 1);
            std::stringstream ss(value);
            float   float_value;
            ss >> float_value;
            csvDataMap[date] = float_value;
        }
    }
    else
        throw(std::runtime_error("Error opening " + dataCsv));
    return csvDataMap;
}

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw(std::runtime_error("No file was passed as input!"));
            
        std::map<std::string, float> dataBase = getCsvData("data.csv");
        
        BitcoinExchange b(std::string(av[1]), dataBase);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

