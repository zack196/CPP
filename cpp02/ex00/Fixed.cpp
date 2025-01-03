#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fix_point_nbr = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n"; 
	fix_point_nbr = src.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		fix_point_nbr = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fix_point_nbr);
}

void	Fixed::setRawBits( int const raw )
{
	fix_point_nbr = raw;
}
