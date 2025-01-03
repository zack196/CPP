#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{}

Point::Point(const Point &fix) : x(fix.x), y(fix.y)
{}

Point::~Point()
{}

Fixed   Point::get_x() const
{
    return (x);
}

Fixed   Point::get_y() const
{
    return (y);
}

Point &	Point::operator=( Point const & rhs )
{
    std::cerr << "You should not assign to const attribut.\n"
        << "You can use copy constructor instead\n";
    (void) rhs;
    return (*this);
}

bool    Point::operator!=(Point const & rhs)const
{
    if ((Fixed)this->x != rhs.x && (Fixed)this->y != rhs.y)
        return (true);
    return false;
}