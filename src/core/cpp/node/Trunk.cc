#include "Trunk.hh"

#include <src/core/cpp/node/Segment.hh>
#include <src/core/cpp/misc/TitleCase.hh>

#include <sstream>

namespace mattmap {

namespace core {

namespace node {

Trunk::Trunk( int id, const std::string &name, const std::string &city )
    : m_id( id )
    , m_name( name )
    , m_city( city )
{

}

Trunk::~Trunk()
{

}

int Trunk::getId() const
{
    return m_id;
}

std::string Trunk::getName() const
{
    return m_name;
}

std::string Trunk::getCity() const
{
    return m_city;
}

const SegmentPtrList &Trunk::getSegments() const
{
    return m_segments;
}

void Trunk::addSegment( const SegmentPtr &segment )
{
    m_segments.push_back(segment);
    const Boundary &newBoundary = m_boundary.refactor( segment->getBoundary() );
    m_boundary = newBoundary;
}

Boundary Trunk::getBoundary() const
{
    return m_boundary;
}

std::string Trunk::toString() const
{
    std::stringstream ss;
    if( m_name.empty() )
    {
        ss << m_id;
    }
    else
    {
        ss << titlecase( m_name ) << ", " << titlecase( m_city );
    }
    return ss.str();
}
std::string Trunk::getLongName() const
{
    std::stringstream ss;
    if( m_name.empty() )
    {
        ss << m_id;
    }
    else
    {
        ss << m_name << ", " << m_city;
    }
    return ss.str();
}

Coordinate Trunk::getCenterPoint() const
{
    return m_boundary.getCenterPoint();
}

EdgePtrs Trunk::getEdges() const
{
    EdgePtrs edges;
    for( const SegmentPtr &segment : m_segments ){
        const EdgePtrList segmentEdges = segment->getEdges();
        edges.insert( segmentEdges.begin(), segmentEdges.end() );
    }
    return edges;
}
	
}

}

}
