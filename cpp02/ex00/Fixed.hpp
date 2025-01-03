#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

class Fixed
{
private:
    int                 fix_point_nbr;
    static const int    nbr_frac_bit = 8;
public:
    /*Constractors*/
    Fixed();
    Fixed(const Fixed &src);
    /*Destractor*/
    ~Fixed();
    /*Operateurs*/
    Fixed&   operator=(const Fixed &rhs);

    /*Seters and Geters*/
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif