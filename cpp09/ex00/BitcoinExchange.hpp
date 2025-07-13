#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _dataBase;
        std::string _fileInput;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& );
        BitcoinExchange&    operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();

        std::string validateDate(const std::string& str);
        float validateAmount(const std::string& str);
        float getValue(std::string date, std::map<std::string, float> dataBase);
        
        BitcoinExchange(const std::string& fileInput, std::map<std::string, float> dataBase) ;

};



#endif