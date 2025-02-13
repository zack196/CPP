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
	Fixed&	operator=(const Fixed &rhs);

	/*Seters and Geters*/
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream &stream, const Fixed & fix);

#endif