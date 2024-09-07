#include"trip.hpp"
using namespace std;

const string DONE_MASS="OK";
const string ACCEPT_HTML=R"(<form action="/accept" method="post">
    <label for="name">Enter your user name:</label><br>
    <input type="text" id="name" name="name"><br><br>
    <input type="hidden" id="id" name="id" value=)";
const string ACCEPT_BUTTON=R"(><input type="submit" value="Accept"></input></form>)";
const string FINISH_HTML=R"(<form action="/finish" method="post">
    <label for="name">Enter your user name:</label><br>
    <input type="text" id="name" name="name"><br><br>
    <input type="hidden" id="id" name="id" value=)";
const string FINISH_BUTTON=R"(><input type="submit" value="Finish" ></input></form>)";

Trip::Trip(string user_name,string orig_name,string dest_name,int trip_id,double trip_cost)
{
    pass_name=user_name;
    origin=orig_name;
    destination=dest_name;
    id=trip_id;
    cost=trip_cost;
}

bool Trip::same_id(int trip_id)
{
    return(id==trip_id);
}

bool Trip::is_waiting()
{
    return(state==WAITING);
}

void Trip::start_trip(string name)
{
    if(state!=WAITING)
        throw(Bad_req());
    state=TRAVELING;
    driver_name=name;
    cout<<DONE_MASS<<'\n';
}

void Trip::trip_ends()
{
    if(state!=TRAVELING)
        throw(Bad_req());
    state=FINISHED;
}

string Trip::finish_accept()
{
    if(state==WAITING)
        return(ACCEPT_HTML+to_string(id)+ACCEPT_BUTTON);
    else if(state==TRAVELING)
        return(FINISH_HTML+to_string(id)+FINISH_BUTTON);
    return("");
}

string Trip::write_inf()
{
    string inf;
    inf+="<tr>";
    inf+="<td>"+to_string(id)+"</td>";
    inf+="<td>"+pass_name+"</td>";
    inf+="<td>"+origin+"</td>";
    inf+="<td>"+destination+"</td>";
    inf+="<td>"+state+"</td>";
    inf+="<td>"+to_string(cost)+"</td>";
    inf+="<td>"+finish_accept()+"</td>";
    inf+="</tr>";
    return(inf);
}