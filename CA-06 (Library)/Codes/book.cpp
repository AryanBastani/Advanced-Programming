#include<iostream>
#include<string>
#include<vector>
#include"book.hpp"
using namespace std;

const int BOOK_BOR_DUR=10;
const int BOOK_MAX_EXD=2;
const int FIRST_PENALTY=2000;
const int SECOND_PENALTY=3000;
const int THIRD_PENALTY=5000;

Book::Book(string name,int num_of_cop)
:Document(name,num_of_cop,BOOK_BOR_DUR,BOOK_MAX_EXD)
{

}

int Book::calculate_penalty(int current_day)
{
    int delay=current_day-Document::calc_ret_time();
    int penalty=0;
    if(delay<0)
        delay=0;

    if(delay>7)
    {
        if(delay>21)
            penalty+=((delay-21)*THIRD_PENALTY+14*SECOND_PENALTY+7*FIRST_PENALTY);  
        else
            penalty+=((delay-7)*SECOND_PENALTY+7*FIRST_PENALTY);
    }
    else
        penalty+=delay*FIRST_PENALTY;
    return(penalty);
}

