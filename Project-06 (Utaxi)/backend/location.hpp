#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__
#include<iostream>
#include<string>

struct Coordinates
{
    double latitude; 
    double longitude;
};

class Location
{
    public:
        Location(std::string city_name,double city_lat,double city_long,int traffic_number);
        bool same_name(std::string city_name);

        Coordinates get_coor() { return(coordinates); };
        int get_traf() { return(traffic); }; 
    private:
        std::string name;
        Coordinates coordinates;
        int traffic;
};
#endif