#include<iostream>
#include<string>
#include<vector>
#include"reference.hpp"
using namespace std;

const int REF_BOR_DUR=5;
const int REF_MAX_EXD=2;
const int FIRST_PENALTY=5000;
const int SECOND_PENALTY=7000;

Reference::Reference(string reference_title,int num_of_cop)
:Document(reference_title,num_of_cop,REF_BOR_DUR,REF_MAX_EXD)
{

}

int Reference::calculate_penalty(int current_day)
{
    int penalty=0;
    int delay=current_day-Document::calc_ret_time();
    if(delay<0)
        delay=0;
    
    if(delay>3)
        penalty+=((delay-3)*SECOND_PENALTY+3*FIRST_PENALTY);
    else
        penalty+=delay*FIRST_PENALTY;
    return(penalty);
}