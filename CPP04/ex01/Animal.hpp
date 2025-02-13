#ifndef Animal_hpp
#define Animal_hpp

# include <iostream>

class Animal
{
protected :
    std::string type;
public:
    Animal();
    Animal(std::string a_type);
    Animal(const Animal &src);
    virtual ~Animal();
    Animal& operator=(const Animal &rhs);

    virtual void    makeSound(void) const;
    std::string    getType() const;
};



#endif