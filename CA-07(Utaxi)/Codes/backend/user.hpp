#ifndef __USER_HPP__
#define __USER_HPP__
#include"exceptions.hpp"
#include<iostream>
#include<vector>
#include<string>

class User
{
    public:
        User(std::string user_name);
        bool same_name(std::string user_name);
        void new_trip();
        void travel_ends();
    private:
        std::string name;
    protected:
        bool is_traveling=false;
};
#endif