#ifndef TRIENODE_HH
#define TRIENODE_HH

#include <string>
#include <vector>
#include <map>
#include <limits>
#include <memory>

namespace mattmap {

namespace core {

namespace node {

template <class T>
class TrieNode
{

private:
    TrieNode();
    ~TrieNode();

    std::vector<T> m_data;

    typedef std::shared_ptr< TrieNode<T> > TrieNodePtr;
    typedef std::map< std::string, TrieNodePtr > TrieNodeMap;
    TrieNodeMap m_children;

public:
    TrieNode( const std::string &keyword, const T &data );

    void addChild( const std::string &keyword, const T &data );
    const std::vector<T> &getData() const;

    std::vector<T> getAllData( int maxResult = INT_MAX ) const;
    std::vector<T> getAll( const std::string &keyword ) const;

private:
    void getAllData_internal( std::vector<T> &data, int maxResults ) const;
    const TrieNodePtr get_internal( const std::string &keyword ) const;

};

}

}

}

#endif // TRIENODE_HH
