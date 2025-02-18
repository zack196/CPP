#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <functional>
#include <utility>
#include <map>

typedef std::string                 string;
typedef std::map<string, double>    map;
typedef std::fstream                fstream;

map	fill_map(const string &dataBase);
std::pair<string, double> get_data(string line);

class BadInputTime : std::exception {};
class BadValue : std::exception {};
class Negative : std::exception {};
class LargeNumber : std::exception {};

// 2024-05-12
#endif
