#include "Point.hpp"

static bool epsilon(float const value) {
    return value >= 0.0 && value <= 1.0;
}

static void calculateBarycentricCoordinates(Point const A, Point const B,
                                            Point const C, Point const P,
                                            Fixed &alpha, Fixed &beta) {
    Fixed const determinant = (
        (B.getY() - C.getY()) * (A.getX() - C.getX()) +
        (C.getX() - B.getX()) * (A.getY() - C.getY())
    );

    alpha = (
        (B.getY() - C.getY()) * (P.getX() - C.getX()) +
        (C.getX() - B.getX()) * (P.getY() - C.getY())
    ) / determinant;

    beta = (
        (C.getY() - A.getY()) * (P.getX() - C.getX()) +
        (A.getX() - C.getX()) * (P.getY() - C.getY())
    ) / determinant;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed alpha;
    Fixed beta;
    calculateBarycentricCoordinates(a, b, c, point, alpha, beta);
    Fixed gamma = Fixed(1) - alpha - beta;

    return (
        epsilon(alpha.toFloat()) &&
        epsilon(beta.toFloat()) &&
        epsilon(gamma.toFloat())
    );
}
