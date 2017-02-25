#ifndef ANGLE_HH
#define ANGLE_HH

#define _USE_MATH_DEFINES

#include <cmath>

namespace mattmap {

namespace core {

namespace util {

double wrap(double angle)
{
    double twoPi = 2 * M_PI;

    while(angle > twoPi)
    {
        angle -= twoPi;
    }

    while(angle < 0)
    {
        angle += twoPi;
    }

    return angle;
}

double reverse(double angle)
{
    return angle + M_PI;
}

}

}

}

#endif // ANGLE_HH
