#ifndef BOUNDARY_HH
#define BOUNDARY_HH

#include <src/core/cpp/node/Coordinate.hh>

namespace mattmap {

namespace core {

namespace node {

class Boundary
{

private:
    Coordinate m_topLeft;
    Coordinate m_bottomRight;

    void refactor_internal( const Coordinate &newCoordiate );

public:
    Boundary();
    Boundary( const Boundary &other );
    Boundary( const Coordinate &topLeft, const Coordinate &bottomRight );
    ~Boundary();

    Boundary refactor( const Coordinate &newCoordiate ) const;
    Boundary refactor( const Boundary &boundary) const;

    Coordinate getTopLeft() const;
    Coordinate getBottomRight() const;

    double getTop() const;
    double getRight() const;
    double getBottom() const;
    double getLeft() const;

    double getWidth() const;
    double getHeight() const;

    double getGPSWidth() const;
    double getGPSHeight() const;

    double getShortestSide() const;
    Coordinate getCenterPoint() const;

    bool contains( const Coordinate &coordinate ) const;
    bool contains( const Boundary &boundary ) const;
    bool isOverlap( const Boundary &boundary ) const;

public:
    static const Coordinate TOP_LEFT;
    static const Coordinate BOTTOM_RIGHT;

};

}

}

}
   
#endif // BOUNDARY_HH
