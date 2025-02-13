#ifndef Animal_hpp
#define Animal_hpp

# include <iostream>

class AAnimal
{
protected :
    std::string type;
public:
    AAnimal();
    AAnimal(std::string a_type);
    AAnimal(const AAnimal &src);
    virtual ~AAnimal();
    AAnimal& operator=(const AAnimal &rhs);

    virtual void    makeSound(void) const = 0;
    std::string    getType() const;
};



#endif