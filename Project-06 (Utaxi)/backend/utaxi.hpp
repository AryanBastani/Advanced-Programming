#ifndef __UTAXI_HPP__
#define __UTAXI_HPP__
#include"passenger.hpp"
#include"driver.hpp"
#include"trip.hpp"
#include"exceptions.hpp"
#include"location.hpp"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
#include<algorithm>

const std::string YES="yes";
const std::string NO="no";
const std::string DRIVER="driver";
const std::string PASSENGER="passenger";


class Utaxi
{
    public:
        Utaxi();
        void read_locations(char *argv[]);
        void ask_trip(std::string user_name,std::string origin,
        std::string destination,double cost);
        void finish_trip(std::string user_name,int id);
        void signup(std::string user_name,std::string role);
        void accept_trip(std::string user_name,int id); 
        void cancel_trips(std::string user_name,int id);
        int handle_trip(std::vector<std::string> cmds,std::string cmd_type);
        std::string write_trips(std::string sort_wants);
        int find_user(std::string user_name,std::string accessed);
    private:
        std::vector<User*> drivers;
        std::vector<User*> passengers;
        std::vector<Trip*> trips;
        std::vector<Location*> locations;
        int trip_counter=0;

        void check_unique(std::string user_name);
        int search_location(std::string location_name);
        int search_trip(int id);
        void delete_trip(int trip_id,int user_id);
        double calc_cost(std::string origin,std::string destination,double hurry_num);
        double calc_dist(Location* origin,Location* destination);
};
std::vector<std::string> split_line(std::string line,char separator);
int search_user(std::string user_name,std::vector<User*> users);
std::string find_inf(std::vector<std::string> cmds,std::string wanted_inf);
bool has_access(int driver_id,int pass_id,std::string accessed);
double hurry_handle(bool in_hurry);
bool sort_by_cost(Trip* trip1,Trip* trip2);
#endif