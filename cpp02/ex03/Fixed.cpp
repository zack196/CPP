#include "Fixed.hpp"

Fixed::Fixed()
{
	fix_point_nbr = 0;
}

Fixed::Fixed(const Fixed &src)
{ 
	*this = src;
}

Fixed::Fixed(const int i)
{
	fix_point_nbr = i << nbr_frac_bit;
}

Fixed::Fixed(const float f)
{
	fix_point_nbr = roundf(f * (1 << nbr_frac_bit));
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		fix_point_nbr = rhs.fix_point_nbr;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (fix_point_nbr);
}

void	Fixed::setRawBits( int const raw )
{
	fix_point_nbr = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)fix_point_nbr / (1 << nbr_frac_bit));
}

int	Fixed::toInt( void ) const
{
	return (fix_point_nbr  >> this->nbr_frac_bit);
}

/* operator<< for ostream */

std::ostream&	operator<<(std::ostream& stream, const Fixed & fix)
{
	stream<< fix.toFloat();
	return (stream);
}

/*comparaison operators*/

bool	Fixed::operator<=(const Fixed &rhs)
{
	if (this->fix_point_nbr <= rhs.fix_point_nbr)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &rhs)
{
	if (this->fix_point_nbr < rhs.fix_point_nbr)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	if (this->fix_point_nbr >= rhs.fix_point_nbr)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &rhs)
{
	if (this->fix_point_nbr > rhs.fix_point_nbr)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	if (this->fix_point_nbr == rhs.fix_point_nbr)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	if (this->fix_point_nbr != rhs.fix_point_nbr)
		return (true);
	return (false);
}

/*arithmetic  operators*/

Fixed  Fixed::operator+(const Fixed &rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed  Fixed::operator-(const Fixed &rhs)
{
	return (Fixed (this->toFloat() - rhs.toFloat()));
}

Fixed  Fixed::operator*(const Fixed &rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
	
}

Fixed  Fixed::operator/(const Fixed &rhs)
{
	return Fixed(this->toFloat() / rhs.toFloat());
	
}

/*Increment and Decrement*/
//https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	// *this = Fixed(this->toFloat() + 1);
	fix_point_nbr = fix_point_nbr + 1;
	return tmp;
}

Fixed	Fixed::operator++()
{
	fix_point_nbr = fix_point_nbr + 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	fix_point_nbr = fix_point_nbr - 1;
	return tmp;
}

Fixed	Fixed::operator--()
{
	fix_point_nbr = fix_point_nbr - 1;
	return *this;
}

/*max and min*/
Fixed&   Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&   Fixed::min(const Fixed &a, const Fixed &b)
{
	if ((Fixed)a < (Fixed)b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}

Fixed&   Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed&   Fixed::max(const Fixed &a, const Fixed &b)
{
	if ((Fixed)a > (Fixed)b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}
