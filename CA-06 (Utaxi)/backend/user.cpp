#include"user.hpp"
using namespace std;

User::User(string user_name)
{
    name=user_name;
}

bool User::same_name(string user_name)
{
    return(name==user_name);
}

void User::new_trip()
{
    if(is_traveling)
        throw(Bad_req());
    is_traveling=true;
}

void User::travel_ends()
{
    is_traveling=false;
}