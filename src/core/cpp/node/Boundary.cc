#include "Boundary.hh"

namespace mattmap {

namespace core {

namespace node {

const Coordinate Boundary::TOP_LEFT = Coordinate( Coordinate::MAX_RIGHT, Coordinate::MAX_BOTTOM );
const Coordinate Boundary::BOTTOM_RIGHT = Coordinate( Coordinate::MAX_LEFT, Coordinate::MAX_TOP );

Boundary::Boundary()
    : m_topLeft( TOP_LEFT )
    , m_bottomRight( BOTTOM_RIGHT )
{
}

Boundary::Boundary( const Boundary &other )
    : m_topLeft( other.m_topLeft )
    , m_bottomRight( other.m_bottomRight )
{
}

Boundary::Boundary( const Coordinate &topLeft, const Coordinate &bottomRight )
    : Boundary()
{
    refactor_internal( topLeft );
    refactor_internal( bottomRight );
}

Boundary::~Boundary()
{

}

void Boundary::refactor_internal( const Coordinate &coordiate )
{
    double top = getTop();
    double right = getRight();
    double bottom = getBottom();
    double left = getLeft();

    if( coordiate.getY() > top )
    {
        top = coordiate.getY();
    }
    if( coordiate.getY() < bottom )
    {
        bottom = coordiate.getY();
    }
    if ( coordiate.getX() > right )
    {
        right = coordiate.getX();
    }
    if( coordiate.getX() < left )
    {
        left = coordiate.getX();
    }

    if( top != getTop() || left != getLeft() )
    {
        m_topLeft = Coordinate( left, top );
    }
    if( bottom != getBottom() || right != getRight() )
    {
        m_bottomRight = Coordinate( right, bottom );
    }
}

Boundary Boundary::refactor( const Coordinate &coordiate ) const
{
    Boundary newBoundary( *this );
    newBoundary.refactor_internal( coordiate );
    return newBoundary;
}

Boundary Boundary::refactor( const Boundary &boundary ) const
{
    Boundary newBoundary( *this );
    newBoundary.refactor_internal( boundary.getTopLeft() );
    newBoundary.refactor_internal( boundary.getBottomRight() );
    return newBoundary;
}

Coordinate Boundary::getTopLeft() const
{
    return m_topLeft;
}

Coordinate Boundary::getBottomRight() const
{
    return m_bottomRight;
}

double Boundary::getTop() const
{
    return m_topLeft.getY();
}

double Boundary::getRight() const
{
    return m_bottomRight.getX();
}

double Boundary::getBottom() const
{
    return m_bottomRight.getY();
}

double Boundary::getLeft() const
{
    return m_topLeft.getX();
}

double Boundary::getWidth() const
{
    return abs( m_topLeft.xDistanceTo( m_bottomRight ) );
}

double Boundary::getGPSWidth() const
{
    return abs( getRight() - getLeft() );
}

double Boundary::getHeight() const
{
    return abs( m_topLeft.yDistanceTo( m_bottomRight ) );
}

double Boundary::getGPSHeight() const
{
    return abs( getTop() - getBottom() );
}

double Boundary::getShortestSide() const
{
    double width = getWidth();
    double height = getHeight();
    return width < height ? width : height;
}

Coordinate Boundary::getCenterPoint() const
{
    return Coordinate( ( getLeft() + getRight() ) / 2, ( getTop() + getBottom() ) / 2 );
}

bool Boundary::contains( const Coordinate &coordinate ) const
{
    return getTop() >= coordinate.getY() && getBottom() <= coordinate.getY()
            && getRight() >= coordinate.getX() && getLeft() <= coordinate.getX();
}

bool Boundary::contains( const Boundary &boundary ) const
{
    return getTop() >= boundary.getTop() && getBottom() <= boundary.getBottom()
            && getRight() >= boundary.getRight() && getLeft() <= boundary.getLeft();
}

bool Boundary::isOverlap( const Boundary &boundary ) const
{
    return getTop() >= boundary.getBottom() && getBottom() <= boundary.getTop()
            && getRight() >= boundary.getLeft() && getLeft() <= boundary.getRight();
}

}

}

}
   

