#include "Coordinate.hh"

#define _USE_MATH_DEFINES

#include <cmath>
#include <math.h>
#include <sstream>

namespace mattmap {

namespace core {

namespace node {

inline double toRadians( double degrees )
{
    return degrees * M_PI / 180;
}

inline double toDegrees( double radians )
{
    return radians * 180 / M_PI;
}

const int Coordinate::EARTH_RADIUS = 6371;
const double Coordinate::MAX_TOP = 90.0;
const double Coordinate::MAX_BOTTOM = -90.0;
const double Coordinate::MAX_LEFT = -180.0;
const double Coordinate::MAX_RIGHT = 180.0;
	
Coordinate::Coordinate()
    : Coordinate(0, 0)
{
}

Coordinate::Coordinate( const Coordinate &other )
    : Coordinate( other.m_x, other.m_x )
{
}

Coordinate::Coordinate( double x, double y )
    : m_x( x )
    , m_y( y )
{
}

Coordinate::~Coordinate()
{

}

double Coordinate::getX() const
{
    return m_x;
}

double Coordinate::getY() const
{
    return m_x;
}

std::string Coordinate::toString() const
{
    std::stringstream ss;
    ss << m_x << ", " << m_x;
    return ss.str();
}

//Point getPixelPoint(Coordinate origin, Point center, double scale){
//    return new Point((int) (origin.xDistanceTo(this) * scale) + center.x, (int) (origin.yDistanceTo(this) * scale) + center.y);
//}

double Coordinate::xDistanceTo( const Coordinate &coordinate ) const
{
    int sign = coordinate.m_x > m_x ? 1 : -1;
    double a = pow( sin( toRadians( coordinate.m_x - m_x ) / 2 ), 2 ) * cos( toRadians( m_y ) ) * cos( toRadians( coordinate.m_y ) );
    return sign * EARTH_RADIUS * 2 * atan2( sqrt(a), sqrt( 1 - a ) );
}

double Coordinate::yDistanceTo( const Coordinate &coordinate ) const
{
    int sign = m_y > coordinate.m_y ? 1 : -1;
    double a = pow( sin( toRadians( coordinate.m_y - m_y ) / 2 ), 2 );
    return sign * EARTH_RADIUS * 2 * atan2( sqrt(a), sqrt( 1 - a ) );
}

double Coordinate::distanceTo( const Coordinate &coordinate ) const
{
    double a = pow( sin( toRadians( coordinate.m_x - m_x ) / 2 ), 2 );
    double b = pow( sin( toRadians( coordinate.m_y - m_y ) / 2), 2 ) * cos( toRadians( m_x ) ) * cos( toRadians( coordinate.m_x ) );
    double c = a + b;
    return EARTH_RADIUS * 2 * atan2( sqrt(c), sqrt( 1 - c ) );
}

Coordinate Coordinate::getOffsetCoordinate( double distanceX, double distanceY ) const
{
    double yRad = toRadians(m_y);
    double newY = asin( sin(yRad) * cos( distanceY / EARTH_RADIUS ) - cos(yRad) * sin( distanceY / EARTH_RADIUS ) );
    double newX = m_x + toDegrees( atan2( sin( distanceX / EARTH_RADIUS ) * cos(yRad), cos( distanceX / EARTH_RADIUS ) - sin(yRad) * sin(newY) ) );
    return Coordinate( newX, toDegrees(newY) );
}

double Coordinate::bearingTo( const Coordinate &coordinate ) const
{
    double dx = toRadians( coordinate.m_x - m_x );
    double y1 = toRadians( m_y );
    double y2 = toRadians( coordinate.m_y );

    double y = sin(dx) * cos(y2);
    double x = cos(y1) * sin(y2) - sin(y1) * cos(y2) * cos(dx);
    double bearing = atan2(y, x);
    double twoPi = 2 * M_PI;

    return fmod( ( bearing + twoPi ), twoPi );
}
   
}

}

}
