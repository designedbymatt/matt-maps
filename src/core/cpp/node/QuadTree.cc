#include "QuadTree.hh"

namespace mattmap {

namespace core {

namespace node {

const double QuadTreeBase::GRAIN_SIZE = 1.0;
	
template <class T>
QuadTree<T>::QuadTree( const Boundary &boundary )
    : QuadTree( boundary, QuadTreeBase::GRAIN_SIZE )
{
}

template <class T>
QuadTree<T>::QuadTree ( const Boundary &boundary, double grain )
    : QuadTree( NULL, boundary, grain )
{
}

template <class T>
QuadTree<T>::QuadTree( const WeakQuadTreePtr &parent, const Boundary &boundary, double grain )
    : m_parent( parent )
    , m_boundary( boundary )
    , m_grain( grain )
{
}

template <class T>
void QuadTree<T>::createQuads()
{
    WeakQuadTreePtr weakPtr( this );
    const Coordinate &centerPoint =  m_boundary.getCenterPoint();

    const int TOP_LEFT = 0;
    const int TOP_RIGHT = 1;
    const int BOTTOM_RIGHT = 2;
    const int BOTTOM_LEFT = 3;

    Boundary topLeft( m_boundary.getTopLeft(), centerPoint );
    m_children[ TOP_LEFT ] = QuadTree<T>( weakPtr, topLeft, grain );
    Boundary topRight( Coordinate( centerPoint.getX(), m_boundary.getTop() ), Coordinate( m_boundary.getRight(), centerPoint.getY() ) );
    m_children[ TOP_RIGHT ] = QuadTree<T>( weakPtr, topRight, grain );

    Boundary bottomRight( centerPoint, m_boundary.getBottomRight() );
    m_children[ BOTTOM_RIGHT ] = QuadTree<T>( weakPtr, bottomRight, grain);
    Boundary bottomLeft( Coordinate( m_boundary.getLeft(), centerPoint.getY() ), Coordinate( centerPoint.getX(), m_boundary.getBottom() ) );
    m_children[ BOTTOM_LEFT ] = QuadTree<T>( weakPtr, bottomLeft, grain );
}

template <class T>
Boundary QuadTree<T>::getBoundary() const
{
    return m_boundary;
}

template <class T>
bool QuadTree<T>::hasChildren() const
{
    return !m_children.isEmpty();
}

template <class T>
const typename QuadTree<T>::QuadTreePtrs &QuadTree<T>::getChildren() const
{
    return m_children;
}

template <class T>
const LayeredData<T> &QuadTree<T>::getData() const
{
    return m_data;
}

template <class T>
double QuadTree<T>::getGrain() const
{
    return m_grain;
}

template <class T>
typename QuadTree<T>::WeakQuadTreePtr QuadTree<T>::getParent() const
{
    return m_parent;
}

template <class T>
bool QuadTree<T>::add( const Boundary &boundary, const T &item, int layer )
{
    if( m_boundary.isOverlap(boundary) )
    {
        m_data.add(item, layer);
        if( m_boundary.getShortestSide() > m_grain * 2 )
        {
            if( m_children.isEmpty() )
            {
                createQuads();
            }
            for( QuadTree<T> child : m_children )
            {
                child.add( boundary, item, layer );
            }
        }
    }
    return true;
}

template <class T>
bool QuadTree<T>::add( const Coordinate &coordinate, const T &item, int layer )
{
    if( m_boundary.contains(coordinate) )
    {
        m_data.add( item, layer );
        if( m_boundary.getShortestSide() > m_grain * 2 )
        {
            if(m_children.isEmpty())
            {
                createQuads();
            }
            for( QuadTree<T> child : m_children )
            {
                child.add( coordinate, item, layer );
            }
        }
    }
    return true;
}

}

}

}
