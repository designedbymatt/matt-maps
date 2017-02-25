#ifndef COORDINATE_HH
#define COORDINATE_HH

#include <string>

namespace mattmap {

namespace core {

namespace node {

class Coordinate
{

private:
    double m_x;
    double m_y;

public:

    Coordinate();
    Coordinate( const Coordinate &other );
    Coordinate( double x, double y );
    ~Coordinate();

    double getX() const;
    double getY() const;

    std::string toString() const;

//    Point getPixelPoint( Coordinate origin, Point center, double scale );

    double xDistanceTo( const Coordinate &coordinate) const;
    double yDistanceTo( const Coordinate &coordinate) const;
    double distanceTo( const Coordinate &coordinate) const;
    double bearingTo( const Coordinate &coordinate ) const;

    Coordinate getOffsetCoordinate( double distanceX, double distanceY ) const;

public:
    static const int EARTH_RADIUS;
    static const double MAX_TOP;
    static const double MAX_BOTTOM;
    static const double MAX_LEFT;
    static const double MAX_RIGHT;

};

}

}

}

#endif // COORDINATE_HH
