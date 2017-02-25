#ifndef LAYEREDDATA_HH
#define LAYEREDDATA_HH

#include <set>
#include <vector>
#include <memory>

namespace mattmap {

namespace core {

namespace node {

template <class T>
class LayeredData
{

public:
    typedef std::set<T> Layer;
    typedef std::shared_ptr< Layer > LayerPtr;
    typedef std::vector< LayerPtr > Layers;

private:
    Layers m_layers;
    const Layer c_empty;

public:
    LayeredData();
    ~LayeredData();

    void add( const T &item, int index );
    const Layer &getLayer( int index ) const;

private:
    const LayerPtr getLayer_internal( int index ) const;

};

}

}

}

#endif // LAYEREDDATA_HH
