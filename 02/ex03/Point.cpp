#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(Point const &pointRef) {
    *this = pointRef;
}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::~Point(void) {}

Point &Point::operator=(Point const &rhs) {
    const_cast<Fixed &>(this->x) = rhs.getX();
    const_cast<Fixed &>(this->y) = rhs.getY();

    return *this;
}

std::ostream &operator<<(std::ostream &os, Point const &pointObject) {
    return os << "(" YELLOW << pointObject.getX() << RES ", " YELLOW
              << pointObject.getY() << RES ")";
}

Fixed Point::getX(void) const {
    return this->x;
}

Fixed Point::getY(void) const {
    return this->y;
}
