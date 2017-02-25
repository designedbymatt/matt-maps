#include "TrieNode.hh"

namespace mattmap {

namespace core {

namespace node {

template <class T>
TrieNode<T>::TrieNode()
{
}

template <class T>
TrieNode<T>::TrieNode( const std::string &keyword, const T &data )
{
    addChild( keyword, data );
}

template <class T>
void TrieNode<T>::addChild( const std::string &keyword, const T &data )
{
    std::string childKey = keyword.substring(0,1);
    bool isLeaf = keyword.length() == 1;
    TrieNodeMap::iterator _it = m_children.find( childKey );
    if( _it == m_children.end() )
    {
        _it = m_children.insert( TrieNodeMap::value_type( childKey, TrieNode<T>() ) ).second;
    }
    if( isLeaf )
    {
        _it->second.m_data.push_back( data );
    }
    else
    {
        _it->second.addChild( keyword.substring(1), data );
    }
}

template <class T>
std::vector<T> TrieNode<T>::getAllData( int maxResults ) const
{
    std::vector<T> allData;
    getAllData_internal( allData, maxResults );
    return allData;
}

template <class T>
void TrieNode<T>::getAllData_internal( std::vector<T> &allData, int maxResults ) const
{
    for( std::vector<T>::const_iterator _it : m_data )
    {
        if( allData.size() >= maxResults )
        {
            return;
        }
        allData.push_back( *_it );
    }

    for( TrieNodeMap::const_iterator _it : m_children )
    {
        _it->second.getAllData( allData, maxResults );
        if( allData.size() >= maxResults )
        {
            return;
        }
    }
}

template <class T>
const typename TrieNode<T>::TrieNodePtr TrieNode<T>::get_internal( const std::string &keyword ) const
{
    std::string childKey = keyword.substring( 0, 1 );
    bool isLeaf = keyword.length() == 1;
    TrieNodeMap::const_iterator _it = m_children.find( childKey );
    if( _it != m_children.end() )
    {
        if( isLeaf )
        {
            return _it.second;
        }
        else
        {
            return _it.second->get( keyword.substring( 1 ) );
        }
    }
    return NULL;
}

template <class T>
const std::vector<T> &TrieNode<T>::getData() const
{
    return m_data;
}

template <class T>
std::vector<T> TrieNode<T>::getAll( const std::string &keyword ) const
{
    TrieNodePtr root = get_internal( keyword );
    if( root != NULL )
    {
        return root->getAllData();
    }
    return std::vector<T>;
}

}

}

}
