#include<iostream>
#include<string>
#include<vector>
#include"magazine.hpp"
using namespace std;

const int MAG_BOR_DUR=2;
const int MAG_MAX_EXD=0;
const int FIRST_PENALTY=2000;
const int SECOND_PENALTY=3000;
const string EXTEND_MAG_MASS="You can’t renew magazines";

Magazine::Magazine(string magazine_title,int pub_year,int num,int copies)
:Document(magazine_title,copies,MAG_BOR_DUR,MAG_MAX_EXD)
{
    year=pub_year;
    number=num;
}

void Magazine::extend(int current_day)
{
    cout<<EXTEND_MAG_MASS<<'\n';
    exit(EXIT_SUCCESS);
}

int Magazine::calculate_penalty(int current_day)
{
    int delay=current_day-Document::calc_ret_time();
    if(delay<0)
        delay=0;

    if(year<1390)
        return(delay*FIRST_PENALTY);

    return(delay*SECOND_PENALTY);
}