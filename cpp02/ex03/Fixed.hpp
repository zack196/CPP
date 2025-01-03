#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fix_point_nbr;
    static const int    nbr_frac_bit = 8;
public:
    /*Constractors*/
    Fixed();
    Fixed(const Fixed &src);
    Fixed(const int i);
    Fixed(const float f);
    
    /*Destractor*/
    ~Fixed();

    /*Operateurs*/
    Fixed&   operator=(const Fixed &rhs);

    /*Comparaisent operators*/
    bool    operator<=(const Fixed &rhs);
    bool    operator<(const Fixed &rhs);
    bool    operator>=(const Fixed &rhs);
    bool    operator>(const Fixed &rhs);
    bool    operator==(const Fixed &rhs);
    bool    operator!=(const Fixed &rhs);

    /*arithmetic  operators*/
    Fixed  operator+(const Fixed &rhs);
    Fixed  operator-(const Fixed &rhs);
    Fixed  operator*(const Fixed &rhs);
    Fixed  operator/(const Fixed &rhs);

    /*Increment and Decrement*/
    Fixed  operator++(int);
    Fixed  operator++();
    Fixed  operator--(int);
    Fixed  operator--();

    /*min and max*/
    static Fixed&   min(Fixed &a, Fixed &b);
    static Fixed&   min(const Fixed &a, const Fixed &b);
    static Fixed&   max(Fixed &a, Fixed &b);
    static Fixed&   max(const Fixed &a, const Fixed &b);

    /*Seters and Geters*/
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream&    operator<<(std::ostream &stream, const Fixed & fix);

#endif