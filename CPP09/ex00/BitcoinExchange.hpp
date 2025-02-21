#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <functional>
# include <utility>
# include <map>
# include <exception>
# include <stdlib.h>
# include <time.h>

typedef std::string                 string;
typedef std::map<string, double>    map;
typedef std::fstream                fstream;

map	fill_map(const string &dataBase);
std::pair<string, double> get_data(string line);


class BadInputTime : public std::exception {
    public :
        virtual const char* what() const throw()
        {
            return "Bad Input Time";
        }
};

class BadValue : public std::exception {
    public :
        virtual const char* what() const throw()
        {
            return "Bad Value";
        }
};

class Negative : public std::exception {
    public :
        virtual const char* what() const throw()
        {
            return "Negative";
        }
};

class LargeNumber : public  std::exception {
    public :
        virtual const char* what() const throw()
        {
            return "Large Number";
        }
};

// 2024-05-12
#endif
