#ifndef __TRIP_HPP__
#define __TRIP_HPP__
#include"exceptions.hpp"
#include<iostream>
#include<iostream>
#include<vector>
#include<string>

const std::string WAITING="waiting";
const std::string TRAVELING="traveling";
const std::string FINISHED="finished";

class Trip 
{
    public:
        Trip(std::string user_name,std::string orig_name,
        std::string dest_name,int trip_id,double trip_cost);
        bool same_id(int trip_id);
        bool is_waiting();
        void start_trip(std::string name);
        void trip_ends();
        std::string write_inf();
        std::string get_pass_name() { return(pass_name); };
        std::string get_driver_name() { return(driver_name); };
        int get_cost() { return(cost); };
    private:
        int id;
        std::string driver_name="";
        std::string pass_name;
        std::string origin;
        std::string destination;
        double cost;
        std::string state=WAITING;

        std::string finish_accept();
};
#endif