#ifndef TRUNK_HH
#define TRUNK_HH

#include <src/core/cpp/Defs.hh>
#include <src/core/cpp/node/Boundary.hh>

namespace mattmap {

namespace core {

namespace node {

class Trunk
{

private:
    int m_id;
    std::string m_name;

    int m_type;
    std::string m_city;

    SegmentPtrList m_segments;
    Boundary m_boundary;
	
public:
    Trunk(int m_id, const std::string &m_name, const std::string &m_city );
    ~Trunk();

    int getId() const;

    std::string getName() const;
    std::string getCity() const;

    const SegmentPtrList &getSegments() const;
    void addSegment( const SegmentPtr &segment );

    Boundary getBoundary() const;

    std::string toString() const;
    std::string getLongName() const;
	
    Coordinate getCenterPoint() const;
    EdgePtrs getEdges() const;
	
};

}

}

}

#endif // TRUNK_HH
