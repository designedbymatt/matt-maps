#ifndef EDGE_HH
#define EDGE_HH

#include <src/core/cpp/Defs.hh>
#include <src/core/cpp/node/Boundary.hh>

namespace mattmap {

namespace core {

namespace node {

class Edge
{

private:

    int m_id;
    double m_distance;
    bool m_directed;

    VertexPtr m_vertex1;
    VertexPtr m_vertex2;

    WeakSegmentPtr m_segment;

    SplinePtr m_spline;
    Boundary m_boundary;
	
public:
    Edge( int m_id, const WeakSegmentPtr &m_segment,
          const VertexPtr &m_vertex1, const VertexPtr &m_vertex2,
          double distance, const SplinePtr &m_spline, const Boundary &m_boundary );
    ~Edge();
	
    int getId() const;
    double getDistance() const;
	
    VertexPtr getDestinatation( const VertexPtr &vertex ) const;
    VertexPtr getStart() const;
    VertexPtr getEnd() const;
	
    WeakSegmentPtr getSegment() const;
	
    const SplinePtr getSpline() const;
	
    Boundary getBoundary() const;
	
    bool hasVertex( const VertexPtr &vertex ) const;
    VertexPtr getOtherVertex( const VertexPtr &vertex ) const;
	
    VertexPtr getNearestVertex( const Coordinate &coordinate ) const;

    void setDirected( bool isDirected );

};

}

}

}

#endif EDGE_HH
