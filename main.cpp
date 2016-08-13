#include <iostream>

using namespace std;

enum class TrafficLights
{
    red,
    yellow,
    green
};

TrafficLights& operator++( TrafficLights& tl)
{
    switch(tl)
    {
        case TrafficLights::green:
            return tl = TrafficLights::yellow;
        case TrafficLights::yellow:
            return tl = TrafficLights::red;
        case TrafficLights::red:
            return tl = TrafficLights::green;
    }

    return tl;
}

string LightsType( TrafficLights& tl)
{
    switch(tl)
    {
        case TrafficLights::green:
            return string( "Green");
        case TrafficLights::yellow:
            return string( "Yellow");
        case TrafficLights::red:
            return string( "Red");
        default:
            return string( "Unknown");
    }
}

int main()
{
    TrafficLights tl = TrafficLights::green;
    cout << LightsType( tl) << endl;
    for( int i = 0; i < 9; i ++)
        cout << LightsType( ++tl) << endl;
    return 0;
}

