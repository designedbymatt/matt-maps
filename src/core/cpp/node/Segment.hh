#ifndef SEGMENT_HH
#define SEGMENT_HH

#include <src/core/cpp/Defs.hh>
#include <src/core/cpp/node/Boundary.hh>

namespace mattmap {

namespace core {

namespace node {

class Segment
{

private:
    int m_id;
    std::string m_name;

    int m_type;

    std::string m_city;
    bool m_isOneWay;
    int m_speed;
    int m_roadClass;
    bool m_noCars;
    bool m_noPedestrians;
    bool m_noBicycles;
	
    Boundary m_boundary;
    WeakTrunkPtr m_trunk;
	
    EdgePtrList m_edges;
	
public:
    Segment( int id );
    ~Segment();

    int getId() const;
    Boundary getBoundary() const;
    std::string toString() const;

    std::string getName() const;
    void setName( const std::string &name );

    const EdgePtrList &getEdges() const;
    void addEdge( const EdgePtr &edge);

    WeakTrunkPtr getTrunk() const;
    void setTrunk( const WeakTrunkPtr &trunk );

    int getType() const;
    void setType( int type );

    std::string getCity() const;
    void setCity( const std::string &city );

    bool getOneWay() const;
    void setOneWay( bool isOneWay );

    int getSpeed() const;
    void setSpeed( int speed );

    int getRoadClass() const;
    void setRoadClass( int roadClass );

    bool isNoCars() const;
    void setNoCars( bool noCars );

    bool isNoPedestrians() const;
    void setNoPedestrians( bool noPedestrians );

    bool isNoBicycles() const;
    void setNoBicycles( bool noBicycles );
	
};

}

}

}

#endif // SEGMENT_HH
