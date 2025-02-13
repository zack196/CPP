#ifndef WrongCat_hpp
#define WrongCat_hpp

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &src);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &rhs);

    void    makeSound(void)const;
    std::string    getType() const;
};

#endif