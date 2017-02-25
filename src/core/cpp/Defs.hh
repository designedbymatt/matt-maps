#ifndef DEFS_HH
#define DEFS_HH

#include <memory>
#include <set>
#include <vector>

#include <src/core/cpp/node/Coordinate.hh>

namespace mattmap {

namespace core {

namespace node {

class Vertex;
typedef std::shared_ptr< Vertex > VertexPtr;
typedef std::weak_ptr< Vertex > WeakVertexPtr;
typedef std::set< VertexPtr > VertexPtrs;

class Segment;
typedef std::shared_ptr< Segment > SegmentPtr;
typedef std::weak_ptr< Segment > WeakSegmentPtr;
typedef std::vector< SegmentPtr > SegmentPtrList;

class Trunk;
typedef std::shared_ptr< Trunk > TrunkPtr;
typedef std::weak_ptr< Trunk > WeakTrunkPtr;

class Edge;
typedef std::shared_ptr< Edge > EdgePtr;
typedef std::weak_ptr< Edge > WeakEdgePtr;
typedef std::set< EdgePtr > EdgePtrs;
typedef std::vector< EdgePtr > EdgePtrList;

typedef std::vector< Coordinate > Spline;
typedef std::shared_ptr< Spline > SplinePtr;
}

}

}

#endif // DEFS_HH
