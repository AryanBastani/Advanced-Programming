#include<iostream>
#include<string>
#include<vector>
using namespace std;

const char FIRST_NUMBER='0';


void result_printer(vector<char> practiced_number,int char_number)
{
    cout<<practiced_number[char_number-1]<<'\n';
}



vector<char> do_practice(int char_number,vector<char>& numbers,vector<char>& practiced_numbers)
{
    if(char_number==1)
    {
        practiced_numbers={'0','1'};
        return(practiced_numbers);
    }

    do_practice(char_number-1,numbers,practiced_numbers);


    if((numbers[char_number-1])=='0')
    {
        practiced_numbers.push_back('0');
        practiced_numbers.push_back('1');
    }

    else
    {
        practiced_numbers.push_back('1');
        practiced_numbers.push_back('0');
    }


    return(practiced_numbers);
}


vector<char> do_numbers_practice(int num_of_times_to_do)
{
vector<char> numbers;


    if(num_of_times_to_do==1)
    {
        numbers={FIRST_NUMBER};
        return(numbers);
    }


    numbers=do_numbers_practice(num_of_times_to_do-1);


    vector<char> practiced_numbers;
    return(do_practice(numbers.size(),numbers,practiced_numbers));
}




int main()
{
    int num_of_times_to_be_do , char_number;


    cin>>num_of_times_to_be_do;
    cin>>char_number;


    vector<char> practiced_numbers=do_numbers_practice(num_of_times_to_be_do);


    result_printer(practiced_numbers,char_number);
}
