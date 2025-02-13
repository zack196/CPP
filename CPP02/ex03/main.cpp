#include "Fixed.hpp"
#include "Point.hpp"
#include <stdio.h>
int main( void )
{
    float x;
    float y;

    std::cout << "/*** Test if the point is inside the triangle ***/\n";
    std::cout << "/*** Enter the triangle vertex ***/\n";

    std::cout << "/*** Point A ***/\n";
    std::cout << "A_x = ";
    std::cin >> x;
    std::cout << "A_y = ";
    std::cin >> y;
    Point   a(x, y);

    std::cout << "/*** Point B ***/\n";
    std::cout << "B_x = ";
    std::cin >> x;
    std::cout << "B_y = ";
    std::cin >> y;
    Point   b(x, y);

    std::cout << "/*** Point C ***/\n";
    std::cout << "C_x = ";
    std::cin >> x;
    std::cout << "C_y = ";
    std::cin >> y;
    Point   c(x, y);

    if (!(a != b && c != b && a != c))
    {
        std::cout << "two or more of those points are confondu\n"; 
        return (1);
    }
    std::cout << "/*** Enter the Point cordonnet ***/\n";
    std::cout << "/*** Point D ***/\n";
    std::cout << "D_x = ";
    std::cin >> x;
    std::cout << "D_y = ";
    std::cin >> y;
    Point   d(x, y);

    bool    test = bsp(a, b, c, d);
    if (test)
        std::cout << "D is in the triangle ABC" << std::endl;
    else
        std::cout << "D is not in the triangle ABC" << std::endl;
    return 0;
}