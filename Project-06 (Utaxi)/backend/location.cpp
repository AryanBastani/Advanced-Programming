#include"location.hpp"
using namespace std;

Location::Location(string city_name,double city_lat,double city_long,int traffic_number)
{
    name=city_name;
    coordinates.latitude=city_lat;
    coordinates.longitude=city_long;
    traffic=traffic_number;
}

bool Location::same_name(string city_name)
{
    return(name==city_name);
}