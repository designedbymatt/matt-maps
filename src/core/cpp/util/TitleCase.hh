#ifndef TITLECASE_HH
#define TITLECASE_HH

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <ctype.h>

namespace mattmap {

namespace core {

namespace util {

inline void split (const std::string &s, char delimeter, std::vector<std::string> &result )
{
    std::stringstream ss;
    ss.str(s);

    std::string item;
    while ( std::getline( ss, item, delimeter ) )
    {
        result.push_back( item );
    }
}



std::string titlecase( const std::string &string )
{
    std::vector<std::string> words;
    split( string, ' ', words );

    std::stringstream ss;
    bool first = true;
    for( const std::string &word : words )
    {
        if( !word.empty() )
        {
            if( !first )
            {
                ss << " ";
            }
            first = false;

            ss << toupper( word[0] ) << word.substr( 1 );
        }
    }
    return ss.str();
}

}

}

}

#endif // TITLECASE_HH
