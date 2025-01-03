#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fix_point_nbr = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n"; 
	*this = src;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	fix_point_nbr = i << nbr_frac_bit;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	fix_point_nbr = roundf(f * (1 << nbr_frac_bit));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		fix_point_nbr = rhs.fix_point_nbr;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
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

std::ostream&	operator<<(std::ostream& stream, const Fixed & fix)
{
	stream<< fix.toFloat();
	return (stream);
}
