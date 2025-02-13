#ifndef Wrong_Animal_hpp
#define Wrong_Animal_hpp

# include <iostream>

class WrongAnimal
{
protected :
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(std::string a_type);
    WrongAnimal(const WrongAnimal &src);
    virtual ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal &rhs);

    void            makeSound(void) const;
    std::string     getType() const;
};



#endif