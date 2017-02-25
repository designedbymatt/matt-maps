#ifndef READABLEUNITS_HH
#define READABLEUNITS_HH

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

namespace mattmap {

namespace core {

namespace util {

std::string hoursToString( double hours )
{
    double minutes = ceil( fmod( hours * 60, 60 ) );
    hours = floor( hours );
    return timeToString(hours, minutes);
}

std::string timeToString( double hours, double minutes )
{
    std::stringstream ss_hours;
    std::stringstream ss_minutes;

    bool
    if( hours > 0 )
    {
        ss_hours << floor( hours ) << " h";
    }
    if( minutes > 0 )
    {
        ss_minutes = floor( minutes ) << " min";
    }

    if( hours > 0 && minutes > 0 )
    {
        ss_hours << " ";
    }

    ss_hours << ss_minutes.str();
    return ss_hours.str();
}

std::string kmToString( double kilometres )
{
    std::stringstream ss;
    if( kilometres > 1 )
    {
        // round to 1 s.f.
        kilometres *= 10;
        kilometres = round( kilometres );
        kilometres *= 0.1;

        ss << std::fixed;
        ss << std::setprecision( 1 );
        ss << kilometres << " km";
        return ss.str();
    }
    else
    {
        ss << round( kilometres * 1000 ) << " m";
        return ss.str();
    }
}

}

}

}

#endif // READABLEUNITS_HH
