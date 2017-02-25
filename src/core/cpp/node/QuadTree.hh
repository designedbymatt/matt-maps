#ifndef QUADTREE_HH
#define QUADTREE_HH

#include <memory>
#include <vector>

#include <src/core/cpp/node/Boundary.hh>
#include <src/core/cpp/node/LayeredData.hh>

namespace mattmap {

namespace core {

namespace node {

class QuadTreeBase
{

protected:
    QuadTreeBase() {}
    ~QuadTreeBase() {}

public:
    static const double GRAIN_SIZE;

};

template <class T>
class QuadTree : QuadTreeBase
{

public:
    typedef std::shared_ptr< QuadTree<T> > QuadTreePtr;
    typedef std::weak_ptr< QuadTree<T> > WeakQuadTreePtr;
    typedef std::vector< QuadTreePtr > QuadTreePtrs;

private:

    double m_grain;

    WeakQuadTreePtr m_parent;
    Boundary m_boundary;
	
    QuadTreePtrs m_children;
    LayeredData<T> m_data;
	
public:
    QuadTree( const Boundary &boundary );
    QuadTree( const Boundary &boundary, double grainSize );
    QuadTree( const WeakQuadTreePtr &parent, const Boundary &boundary, double grain );
    ~QuadTree();

private:
    void createQuads();

public:

    Boundary getBoundary() const;
    double getGrain() const;

    WeakQuadTreePtr getParent() const;

    bool hasChildren() const;
    const QuadTreePtrs &getChildren() const;

    bool add( const Boundary &boundary, const T &item, int layer = 0 );
    bool add( const Coordinate &coordinate, const T &item, int layer = 0 );

    const LayeredData<T> &getData() const;

};

}

}

}

#endif // QUADTREE_HH
