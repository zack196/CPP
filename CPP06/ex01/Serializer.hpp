#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int         i;
    char        c;
    char*       s;
    double      d;
    float       f;
    Data        *next;
};

class Serializer
{
public:
    static Data* deserialize(uintptr_t raw);
    static uintptr_t serialize(Data* ptr);
private:
    Serializer();
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& rhs);
    ~Serializer();
};


#endif