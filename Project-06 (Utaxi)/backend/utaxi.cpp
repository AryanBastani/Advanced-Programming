#include"utaxi.hpp"
using namespace std;

const string FIRST_CMD_TYPE="POST";
const string SECOND_CMD_TYPE="GET";
const string THIRD_CMD_TYPE="DELETE";

const string SIGNUP_CMD="signup";
const string TRIP_FINISH_CMD="finish";
const string TRIP_ASK_CMD="trips";
const string TRIP_ACCEPT_CMD="accept";

const char COMMANDS_SEPARATOR=' ';
const char LOCS_SEPARATOR=',';
const string SEPARATOR="?";

const string USER_NAME="username";
const string ROLE="role";
const string ORIGIN="origin";
const string DESTINATION="destination";
const string ID="id";
const string TRIPS="trips";
const string COST="cost";
const string IN_HURRY="in_hurry";
const string HURRY_MASS="yes";
const string NO_HURRY_MASS="no";
const string SORT_BY_COST="sort_by_cost";


const string DONE_MASS="OK";

const int NOT_FOUND=-1;
const string ASK_TRIP="no";
const string GET_COST="yes";

const int INIZIAL_PRICE=10000;
const double DEGREE_LENGTH=110.5;
const double HURRY_NUM=1.2;
const double NO_HURRY_NUM=1;


Utaxi::Utaxi()
{

}

vector<string> split_line(string line,char separator)
{
    vector<string> spiliteds;
    string spred_word;
    for(int char_id=0;char_id<(int)line.size();char_id++)
    {
        if(line[char_id]==separator)
        {
            spiliteds.push_back(spred_word);
            spred_word="";
        }
        else
            spred_word+=line[char_id];
    }
    spiliteds.push_back(spred_word);
    return(spiliteds);
}

int search_user(string user_name,vector<User*> users)
{
    for(int user_id=0;user_id<(int)users.size();user_id++)
    {
        if(users[user_id]->same_name(user_name))
            return(user_id);
    }
    return(NOT_FOUND);
}

int Utaxi::search_location(string location_name)
{
    for(int location_id=0;location_id<(int)locations.size();location_id++)
    {
        if(locations[location_id]->same_name(location_name))
            return(location_id);
    }
    return(NOT_FOUND);
}

string find_inf(vector<string> cmds,string wanted_inf)
{
    if(cmds[2]==SEPARATOR)
    {
        for(int cmd_id=0;cmd_id<(int)cmds.size();cmd_id++)
        {
            if(cmds[cmd_id]==wanted_inf&&(int)cmds.size()>(cmd_id+1))
                return(cmds[cmd_id+1]);
        }
    }
    throw(Bad_req());
}

void Utaxi::check_unique(string user_name)
{
    if(search_user(user_name,drivers)!=NOT_FOUND||
    search_user(user_name,passengers)!=NOT_FOUND)
        throw(Bad_req());
}

void Utaxi::signup(string user_name ,string role)
{
    check_unique(user_name);
    if(role==DRIVER)
        drivers.push_back(new Driver(user_name));
    else if(role==PASSENGER)
        passengers.push_back(new Passenger(user_name));
    else
        throw(Bad_req());
}

bool has_access(int driver_id,int pass_id,string accessed)
{
    return((driver_id!=NOT_FOUND&&accessed==DRIVER)||
    (pass_id!=NOT_FOUND&&accessed==PASSENGER));
}

int Utaxi::find_user(string user_name,string accessed)
{
    int driver_id=search_user(user_name,drivers);
    int pass_id=search_user(user_name,passengers);

    if(driver_id==NOT_FOUND&&pass_id==NOT_FOUND)
        throw(Not_found());
    else if(!has_access(driver_id,pass_id,accessed))
        throw(Permission_den());
    
    if(driver_id!=NOT_FOUND)
        return(driver_id);
    return(pass_id);
}

double Utaxi::calc_dist(Location* origin,Location* destination)
{
    Coordinates orig_coor=origin->get_coor();
    Coordinates dest_coor=destination->get_coor();
    double delta_lat=dest_coor.latitude-orig_coor.latitude;
    double delta_lng=dest_coor.longitude-orig_coor.longitude;

    return(DEGREE_LENGTH*sqrt(pow(delta_lat,2)+pow(delta_lng,2)));
}

double Utaxi::calc_cost(string origin_name,string destin_name,double hurry_num)
{
    int origin_id=search_location(origin_name);
    int destination_id=search_location(destin_name);
    if(origin_id==NOT_FOUND||destination_id==NOT_FOUND) 
        throw(Not_found());

    Location* origin=locations[origin_id];
    Location* destination=locations[destination_id];
    double dist=calc_dist(origin,destination);
    return(dist*(origin->get_traf()+destination->
    get_traf())*INIZIAL_PRICE*hurry_num);
}

void Utaxi::ask_trip(string user_name,string origin,
string destination,double cost)
{   
    trip_counter++;
    trips.push_back(new Trip(user_name,origin,
    destination,trip_counter,cost));
}

double hurry_handle(string in_hurry)
{
    if(in_hurry==HURRY_MASS)
        return(HURRY_NUM);
    else if(in_hurry==NO_HURRY_MASS)
        return(NO_HURRY_NUM);
    throw(Bad_req());
}

int Utaxi::handle_trip(vector<string> cmds,string cmd_type)
{
    string user_name=cmds[0];
    string origin=cmds[1];
    string destination=cmds[2];
    double hurry_num=hurry_handle(cmds[3]);
    int user_id=find_user(user_name,PASSENGER);
    double cost=calc_cost(origin,destination,hurry_num);

    if(cmd_type==ASK_TRIP)
    {
        ask_trip(user_name,origin,destination,cost);
        passengers[user_id]->new_trip();
        return(trip_counter);
    }
    else
        return(cost);
}
 
void Utaxi::accept_trip(string user_name,int id)
{
    int trip_id=search_trip(id);

    drivers[find_user(user_name,DRIVER)]->new_trip();
    trips[trip_id]->start_trip(user_name);
}

void Utaxi::finish_trip(string user_name,int id)
{
    int trip_id=search_trip(id);
    int user_id=find_user(user_name,DRIVER);

    if(!drivers[user_id]->same_name(trips[trip_id]->get_driver_name()))
        throw(Permission_den());

    trips[trip_id]->trip_ends();
    drivers[user_id]->travel_ends();
    passengers[search_user(trips[trip_id]->
    get_pass_name(),passengers)]->travel_ends();
    cout<<DONE_MASS<<'\n';
}


int Utaxi::search_trip(int id)
{
    for(int trip_id=0;trip_id<(int)trips.size();trip_id++)
    {
        if(trips[trip_id]->same_id(id))
            return(trip_id);
    }
    throw(Not_found());
}

bool sort_by_cost(Trip* trip1,Trip* trip2)
{
    int first_cost=trip1->get_cost();
    int second_cost=trip2->get_cost();
    if(first_cost==second_cost)
        return(false);
    return(second_cost<first_cost);
}

string Utaxi::write_trips(string sort_wants)
{   
    string trips_list;
    vector<Trip*> sorted_trips=trips;
    if(sort_wants==YES)
        sort(sorted_trips.begin(),sorted_trips.end(),sort_by_cost);
    else if(sort_wants!=NO)
        throw(Bad_req());

    for(int trip_id=0;trip_id<(int)sorted_trips.size();trip_id++)
    {
        trips_list+=sorted_trips[trip_id]->write_inf();
    }
    trips_list+="</table>";
    return(trips_list);
}

void Utaxi::delete_trip(int trip_id,int user_id)
{
    if(!(trips[trip_id]->is_waiting()))
        throw(Bad_req());
    trips.erase(trips.begin()+trip_id);
    passengers[user_id]->travel_ends();
    cout<<DONE_MASS<<'\n';
}

void Utaxi::cancel_trips(string user_name,int id)
{
    int trip_id=search_trip(id);
    int user_id=search_user(user_name,passengers);

    if(!passengers[user_id]->
    same_name(trips[trip_id]->get_pass_name()))
        throw(Permission_den());

    delete_trip(trip_id,user_id);
}

void Utaxi::read_locations(char *argv[])
{
    string line;
    ifstream locations_file;
    locations_file.open(argv[1]);
    locations_file>>line;

    while(locations_file>>line)
    {
        vector<string> location_infs=split_line(line,LOCS_SEPARATOR);
        locations.push_back(new Location(location_infs[0],stod(
        location_infs[1]),stod(location_infs[2]),stoi(location_infs[3])));
    }

    locations_file.close();
}