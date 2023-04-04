#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const x;
        Fixed const y;
    
    public:
        Point(void);
        Point(Point const &pointRef);
        Point(float const x, float const y);
        ~Point(void);

        Point &operator=(Point const &rhs);

        Fixed getX(void) const;
        Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &os, Point const &pointObject);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
