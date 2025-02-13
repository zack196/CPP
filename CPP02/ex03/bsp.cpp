#include "Point.hpp"


bool segment_side_check( Point const A, Point const B, Point const C, Point const point )
{

    if (A.get_x() != B.get_x())
    {
        Fixed   alpha;
        Fixed   beta;
        bool    point_down;

        alpha = (A.get_y() - B.get_y()) / (A.get_x() - B.get_x());
        beta = A.get_y() - (alpha * A.get_x());

        point_down = false;
        if (C.get_y() < alpha * C.get_x() + beta )
            point_down = true;

        if (point_down && (point.get_y() < (alpha * point.get_x()) + beta))
            return (true);

        if (!point_down && (point.get_y() > (alpha * point.get_x()) + beta))
            return (true);
    }
    else
    {
        bool    point_left;

        point_left = false;
        if (C.get_x() > A.get_x())
            point_left = true;
        
        if (point_left && (point.get_x() > A.get_x()))
            return true;
        if (!point_left && (point.get_x() < A.get_x()))
            return true;
    }

    return (false);

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    bool ab;
    bool ac;
    bool bc;

    ab = segment_side_check(a, b, c, point);
    ac = segment_side_check(a, c, b, point);
    bc = segment_side_check(b, c, a, point);
    return (ab && ac && bc);
}