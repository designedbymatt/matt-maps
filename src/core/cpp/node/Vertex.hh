#ifndef VERTEX_HH
#define VERTEX_HH

#include <memory>
#include <map>
#include <set>

#include <src/core/cpp/Defs.hh>
#include <src/core/cpp/node/Coordinate.hh>

namespace mattmap {

namespace core {

namespace node {

class Vertex{

private :
    int m_id;
    Coordinate m_coordinate;
    EdgePtrs m_outgoingEdges;
    EdgePtrs m_incomingEdges;
    EdgePtrs m_allEdges;

    typedef std::map< EdgePtr, EdgePtrs > RestrictionMap;
    RestrictionMap m_restrictions;
	
public:
    Vertex( int id, const Coordinate &coordinate );
    ~Vertex();

    int getId() const;
    Coordinate getCoordinate() const;

    void addEdge( const EdgePtr &edge );
	
    const EdgePtrs &getAllEdges() const;
	
    const EdgePtrs &getOutgoingEdges() const;
    EdgePtrs getOutgoingEdges( const EdgePtr &previousEdge ) const;

    const EdgePtrs &getIncomingEdges() const;

    void removeIncomingEdge( const EdgePtr &edge );
    void removeOutgoingEdge( const EdgePtr &edge );

    void addRestriction( const EdgePtr &from, const EdgePtr &to );

};

}

}

}

#endif // VERTEX_HH
