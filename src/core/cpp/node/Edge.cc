#include "Edge.hh"

#include <src/core/cpp/node/Vertex.hh>

namespace mattmap {

namespace core {

namespace node {

Edge::Edge( int id, const WeakSegmentPtr &segment,
            const VertexPtr &vertex1, const VertexPtr &vertex2,
            double distance, const SplinePtr &spline, const Boundary &boundary )
    : m_id( id )
    , m_segment( segment )
    , m_vertex1( vertex1 )
    , m_vertex2( vertex2 )
    , m_spline( spline )
    , m_boundary( boundary )
    , m_distance( distance )
    , m_directed( false )
{
}

Edge::~Edge()
{

}

int Edge::getId() const
{
    return m_id;
}

double Edge::getDistance() const
{
    return m_distance;
}

VertexPtr Edge::getDestinatation( const VertexPtr &vertex ) const
{
    if( vertex == m_vertex1 )
    {
        return m_vertex2;
    }
    else if( vertex == m_vertex2 )
    {
        return m_vertex1;
    }
    return NULL;
}

VertexPtr Edge::getStart() const
{
    return m_vertex1;
}

VertexPtr Edge::getEnd() const
{
    return m_vertex2;
}

WeakSegmentPtr Edge::getSegment() const
{
    return m_segment;
}

const SplinePtr Edge::getSpline() const
{
    return m_spline;
}

Boundary Edge::getBoundary() const
{
    return m_boundary;
}

VertexPtr Edge::getOtherVertex( const VertexPtr &vertex ) const
{
    if( m_vertex1 == vertex )
    {
        return m_vertex2;
    }
    else if ( m_vertex2 == vertex )
    {
        return m_vertex1;
    }
    return NULL;
}

VertexPtr Edge::getNearestVertex( const Coordinate &coordinate ) const
{
    double vertex1Dist = m_vertex1->getCoordinate().distanceTo(coordinate);
    double vertex2Dist = m_vertex2->getCoordinate().distanceTo(coordinate);

    return vertex1Dist < vertex2Dist ? m_vertex1 : m_vertex2;
}

void Edge::setDirected( bool directed )
{
    if( directed == m_directed )
    {
        return;
    }

    EdgePtr self( this );
    if( directed )
    {
        m_vertex1->removeIncomingEdge( self );
        m_vertex2->removeOutgoingEdge( self );
    }
    else
    {
        m_vertex1->addEdge( self );
        m_vertex2->addEdge( self );
    }
    m_directed = directed;
}

bool Edge::hasVertex( const VertexPtr &vertex ) const
{
    return vertex == m_vertex1 || vertex == m_vertex2;
}

}

}

}
