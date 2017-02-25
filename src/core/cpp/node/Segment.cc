#include "Segment.hh"

#include <src/core/cpp/node/Edge.hh>

#include <sstream>

namespace mattmap {

namespace core {

namespace node {

Segment::Segment( int id )
    : m_id( id )
{
}

Segment::~Segment()
{
}

int Segment::getId() const
{
    return m_id;
}

Boundary Segment::getBoundary() const
{
    return m_boundary;
}

std::string Segment::getName() const
{
    return m_name;
}

const EdgePtrList &Segment::getEdges() const
{
    return m_edges;
}

void Segment::addEdge( const EdgePtr &edge )
{
    m_edges.push_back( edge );
    const Boundary &newBoundary = m_boundary.refactor( edge->getBoundary() );
    m_boundary = newBoundary;
}

void Segment::setTrunk( const WeakTrunkPtr &trunk )
{
    m_trunk = trunk;
}

WeakTrunkPtr Segment::getTrunk() const
{
    return m_trunk;
}

std::string Segment::toString() const
{
    std::stringstream ss;
    if( m_name.empty() )
    {
        ss << m_id;
    }
    else
    {
        ss << m_name;
        if( !m_city.empty() )
        {
            ss << ", " << m_city;
        }
    }
    return ss.str();
}

void Segment::setName( const std::string &name )
{
    m_name = name;
}

int Segment::getType() const
{
    return m_type;
}

void Segment::setType(int type)
{
    m_type = type;
}

std::string Segment::getCity() const
{
    return m_city;
}

void Segment::setCity( const std::string &city )
{
    m_city = city;
}

bool Segment::getOneWay() const
{
    return m_isOneWay;
}

void Segment::setOneWay(bool isOneWay)
{
    m_isOneWay = isOneWay;
    for( EdgePtr &edge : m_edges )
    {
        edge->setDirected( isOneWay );
    }
}

int Segment::getSpeed() const
{
    switch( m_speed )
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 60;
    case 4:
        return 60;
    case 5:
        return 70;
    case 6:
        return 100;
    default:
        return 1;
    }
}

void Segment::setSpeed(int speed)
{
    m_speed = speed;
}

int Segment::getRoadClass() const
{
    return m_roadClass;
}

void Segment::setRoadClass(int roadClass)
{
    m_roadClass = roadClass;
}

bool Segment::isNoCars() const
{
    return m_noCars;
}

void Segment::setNoCars( bool noCars )
{
    m_noCars = noCars;
}

bool Segment::isNoPedestrians() const
{
    return m_noPedestrians;
}

void Segment::setNoPedestrians(bool noPedestrians)
{
    m_noPedestrians = noPedestrians;
}

bool Segment::isNoBicycles() const
{
    return m_noBicycles;
}

void Segment::setNoBicycles(bool noBicycles)
{
    m_noBicycles = noBicycles;
}
	
}

}

}
