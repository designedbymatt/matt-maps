#include "Vertex.hh"

namespace mattmap {

namespace core {

namespace node {

Vertex::Vertex( int id, const Coordinate &coordinate )
    : m_id( id )
    , m_coordinate( coordinate )
{

}

int Vertex::getId() const
{
    return m_id;
}

void Vertex::addEdge( const EdgePtr &edge )
{
    m_outgoingEdges.insert( edge );
    m_incomingEdges.insert( edge );
    m_allEdges.insert( edge );
}

Coordinate Vertex::getCoordinate() const
{
    return m_coordinate;
}

const EdgePtrs &Vertex::getAllEdges() const
{
    return m_allEdges;
}

const EdgePtrs &Vertex::getOutgoingEdges() const
{
    return m_outgoingEdges;
}

EdgePtrs Vertex::getOutgoingEdges( const EdgePtr &previousEdge ) const
{
    RestrictionMap::const_iterator _it = m_restrictions.find( previousEdge );
    if( _it == m_restrictions.end() )
    {
        return m_outgoingEdges;
    }

    EdgePtrs outgoingEdges;
    const EdgePtrs &restrictions = _it->second;
    for( const EdgePtr &edge : m_outgoingEdges )
    {
        if( restrictions.find( edge ) == restrictions.end() )
        {
            outgoingEdges.insert( edge );
        }
    }
    return outgoingEdges;
}

const EdgePtrs &Vertex::getIncomingEdges() const
{
    return m_incomingEdges;
}

void Vertex::removeIncomingEdge( const EdgePtr &edge )
{
    m_incomingEdges.erase( edge );
}

void Vertex::removeOutgoingEdge( const EdgePtr &edge )
{
    m_outgoingEdges.erase( edge );
}

void Vertex::addRestriction( const EdgePtr &from, const EdgePtr &to )
{
    m_restrictions[ from ].insert( to );
}

}

}

}
