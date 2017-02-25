#include "LayeredData.hh"

namespace mattmap {

namespace core {

namespace node {

template <class T>
LayeredData<T>::LayeredData()
    : c_empty()
{
}

template <class T>
LayeredData<T>::~LayeredData()
{
}

template <class T>
void LayeredData<T>::add( const T &item, int index )
{
    for( int i = m_layers.size(); i < index + 1; ++i )
    {
        LayerPtr layer( new Layer<T>() );
        m_layers.push_back( layer );
    }
    while( index >= 0 )
    {
        m_layers[ index ]->push_pack(item);
        --index;
    }
}

template <class T>
const typename LayeredData<T>::Layer &LayeredData<T>::getLayer( int index ) const
{
    LayerPtr layer = getLayer_internal( index );
    if( layer )
    {
        return layer.get();
    }

    return c_empty;
}

template <class T>
const typename LayeredData<T>::LayerPtr LayeredData<T>::getLayer_internal( int index ) const
{
    if( index < m_layers.size() )
    {
        return m_layers[ index ];
    }

    return NULL;
}

}

}

}
