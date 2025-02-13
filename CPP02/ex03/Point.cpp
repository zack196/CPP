#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)){}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)){}

Point::Point(const Point &fix) : x(fix.x), y(fix.y){}

Point::~Point(){}

Fixed   Point::get_x() const
{
    return x;
}

Fixed   Point::get_y() const
{
    return y;
}

Point &	Point::operator=( Point const &rhs )
{
    if (&rhs != this)
    {
        (Fixed) x = rhs.get_x();
        (Fixed) y = rhs.get_y();
    }
    return *this;
}

bool    Point::operator!=(Point const & rhs)
{
    return ((this->x != rhs.x) || (this->y != rhs.y));
}
