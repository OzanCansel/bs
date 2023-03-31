#include <iostream>
#include <rbs/rbs.hpp>
#include "helper.hpp"

struct coordinate
{
    float x;
    float y;
    float z;
};

template<>
struct rbs::aggregate_serializable<coordinate> : std::true_type
{};

int main()
{
    rbs::stream bes { rbs::endian::big    };
    rbs::stream les { rbs::endian::little };

    coordinate coord { 1.0f , 2.0f , 3.0f };

    bes << coord;
    les << coord;

    print( "little -> coordinate" , bes );
    print( "big    -> coordinate" , les );
}