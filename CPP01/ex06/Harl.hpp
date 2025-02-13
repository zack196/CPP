#ifndef Harl_hpp
#define Harl_hpp

#include <iostream>

enum complaining {NOT_RELEVENT, DEBUG, INFO, WARNING, ERROR};
class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl();
    ~Harl();
    void complain( complaining level );
};

#endif