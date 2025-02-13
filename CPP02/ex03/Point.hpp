#ifndef Point_hpp
# define Point_hpp


# include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    /*Constructors*/
    Point();
    Point(const float x, const float y);
    Point(const Point &fix);
    
    Fixed   get_x() const;
    Fixed   get_y() const;
    
    /*Destroctors*/
    ~Point();

    Point &	operator=( Point const & rhs );
    bool    operator!=(Point const & rhs);

    /**/


};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif