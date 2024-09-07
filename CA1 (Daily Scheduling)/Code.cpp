#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


string additional_eraser(string times_line)
{
    for(int additional_char_number=2;additional_char_number<=6;additional_char_number+=2)
    {
    times_line.erase((times_line.begin()+additional_char_number));
    }


    return(times_line);
}


string time_to_minute(int time)
{
string minute;


minute=to_string((time%100));
       if((time%100)<10)
       {
           minute.insert(minute.begin(),'0');
       }


return(minute);
}



string time_to_hour(int time)
{
string hour;
hour=to_string((time/100));


return(hour);
}


void task_times_printer(vector<vector<int>> task_times_interval)
{
string first_hour,first_minute,second_hour,second_minute;


    for(int task_time_id=1;task_time_id<=(task_times_interval.size());task_time_id++)
    { 
    first_hour=time_to_hour(task_times_interval[(task_time_id-1)][0]);
    second_hour=time_to_hour(task_times_interval[(task_time_id-1)][1]);
    first_minute=time_to_minute(task_times_interval[(task_time_id-1)][0]);
    second_minute=time_to_minute(task_times_interval[(task_time_id-1)][1]);


    cout<<task_time_id<<' '<<first_hour<<':'<<first_minute<<'-'<<second_hour<<':'<<second_minute<<'\n';
    }
}







int main()
{
    vector< int > meeting_times;
    vector< vector<int> > free_times_interval={{1200,2000}};
    vector<vector<int> > task_times_interval;
    string input_line ,first_hour,first_minute,second_hour,second_minute;
    int two_times , first_time , second_time,free_time_id,task_duration,do_times_end=1;


    while(cin>>input_line)
    {
        if(input_line=="#")
        {
        do_times_end=0;
        continue;
        }


        if(do_times_end==1)
        {
        two_times=stoi(additional_eraser(input_line));
        first_time=(two_times/10000);
        second_time=(two_times%10000);


    if(first_time==free_times_interval[(free_times_interval.size()-1)][0])
        {
        free_times_interval[(free_times_interval.size()-1)][0]=second_time;
        }


    else if(second_time==free_times_interval[(free_times_interval.size()-1)][1]) 
        {
        free_times_interval[(free_times_interval.size()-1)][1]=first_time;
        }


    else
        {
        free_times_interval[(free_times_interval.size()-1)][1]=first_time;
        free_times_interval.push_back({second_time,2000});
        }

        }


        else
        {
        task_duration=stoi(input_line);
        cin>>free_time_id;


        task_times_interval.push_back({(free_times_interval[(free_time_id-1)][0]),
        (free_times_interval[(free_time_id-1)][0]+(task_duration%60))});
         if (task_duration>=60)
           {
               task_times_interval[(task_times_interval.size()-1)][1] =
               (task_times_interval[(task_times_interval.size()-1)][1] + ((task_duration/60)*100));
           }



        free_times_interval[(free_time_id-1)][0]=task_times_interval[(task_times_interval.size()-1)][1];
        }
    }
    task_times_printer(task_times_interval);
}