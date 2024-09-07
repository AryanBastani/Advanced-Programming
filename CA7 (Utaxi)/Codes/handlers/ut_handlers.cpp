#include "ut_handlers.hpp"
using namespace std;

const int ACCEPT=0;
const int FINISH=1;
const string SORT=R"(<br><br> <form action="/show_trips" method="post">
    <label for="name"></label><br>
    <input type="hidden" id="name" name="name" value=")";
const string UNSORT=R"(<br><br> <form action="/show_sorted" method="post">
    <label for="name"></label><br>
    <input type="hidden" id="name" name="name" value=")";
const string SORT_AFT_NME=R"(">
    <input type="submit" value="Unsort trips"></input></form><br><br>)";
const string UNSORT_AFT_NME=R"(">
    <input type="submit" value="Sort trips by cost"></input></form><br><br>)";
const string HOME_BUTTON=R"(<form action="/" method="get">
     <input type="submit" value="Go Home" ></input></form></body></html>)";


Utaxi_handler::Utaxi_handler(Utaxi *the_utaxi)
{
  utaxi=the_utaxi;
}

Signup_handler::Signup_handler(Utaxi *the_utaxi)
:Utaxi_handler(the_utaxi)
{
}

Ask_handler::Ask_handler(Utaxi *the_utaxi)
:Utaxi_handler(the_utaxi)
{

}

Cancel_handler::Cancel_handler(Utaxi *the_utaxi)
:Utaxi_handler(the_utaxi)
{

}

Show_handler::Show_handler(Utaxi *the_utaxi,string sort)
:Utaxi_handler(the_utaxi)
{
  sorted_wants=sort;
}

Accept_handler::Accept_handler(Utaxi *the_utaxi)
:Utaxi_handler(the_utaxi)
{

}

Finish_handler::Finish_handler(Utaxi *the_utaxi)
:Utaxi_handler(the_utaxi)
{

}

Response *Signup_handler::callback(Request *req) 
{
  string username = req->getBodyParam("name");
  string role = req->getBodyParam("role");
  try
  {
    utaxi->signup(username,role);
    return (Response::redirect("/done"));
  }
  catch(Ut_error& ut_error)
  {
    return(find_error(ut_error));
  }
}

Response *Ask_handler::ask_page(int out_put,string without_asking)
{
  Response *res = new Response;
  string before_out;
  string line;
  ifstream before("static/before_ouutput.html");
  while(before>>line)
    before_out+=line;
  res->setHeader("Content-Type", "text/html");
  if(without_asking==YES)
    res->setBody(before_out+R"(The trip's cost is:)"+to_string(out_put)+AFTER_OUTPUT);
  else
    res->setBody(before_out+R"(Your trip's id is:)"+to_string(out_put)+AFTER_OUTPUT);
  return(res);
}

Response *Ask_handler::callback(Request *req)
{
  vector <string> ask_inf = { req->getBodyParam("name"),req->
  getBodyParam("origin"),req->getBodyParam("destination"),req->
  getBodyParam("in_hurry") };
  string without_asking = req->getBodyParam("without_asking");
  try
  { 
    int out_put=utaxi->handle_trip(ask_inf,without_asking);
    return (ask_page(out_put,without_asking));
  }
  catch(Ut_error& ut_error)
  {
    return(find_error(ut_error));
  }
}

Response *Cancel_handler::callback(Request *req)
{
  string username=req->getBodyParam("name");
  string trip_id=req->getBodyParam("trip_id");
  try
  {
    utaxi->cancel_trips(username,stoi(trip_id));
    return(Response::redirect("/done"));
  }
  catch(Ut_error& ut_error)
  {
    return(find_error(ut_error));
  }

}

string Show_handler::add_head()
{
  string head;
  head+="<table>";
  head+="<tr>";
  head+="<th> Trip id </th>";
  head+="<th> Passenger </th>";
  head+="<th> Origin </th>";
  head+="<th> Destination </th>";
  head+="<th> State </th>";
  head+="<th> Cost </th>";
  head+="<th> </th>";
  head+="</tr>";
  return(head);
}

string Show_handler::add_end(string username)
{   
  string end;
  if(sorted_wants==YES) 
    end=SORT+username+SORT_AFT_NME;
  else
    end=UNSORT+username+UNSORT_AFT_NME;
  end+=HOME_BUTTON;
  return(end);
}

Response *Show_handler::show_works(string username)
{
  string show_html;
  string line;
  ifstream html("static/show.html");
  while(html>>line)
    show_html+=line;

  utaxi->find_user(username,DRIVER);

  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  show_html+=add_head();
  show_html+=utaxi->write_trips(sorted_wants);
  show_html+=add_end(username);
  res->setBody(show_html);
  return(res);
}

Response *Show_handler::callback(Request *req)
{
    string username=req->getBodyParam("name");
    try
    {
      return(show_works(username));
    }
    catch(Ut_error& ut_error)
    {
      return(find_error(ut_error));
    }
}

Response *Utaxi_handler::fin_acc(int type,Request *req)
{
  string username= req->getBodyParam("name");
  string trip_id= req->getBodyParam("id");
  try
  {
    if(type==ACCEPT)
      utaxi->accept_trip(username,stoi(trip_id));
    else
      utaxi->finish_trip(username,stoi(trip_id));
    return (Response::redirect("/done"));
  }
  catch(Ut_error& ut_error)
  {
    return(find_error(ut_error));
  }
}

Response *Accept_handler::callback(Request *req)
{
  return(fin_acc(ACCEPT,req));
}

Response*Finish_handler::callback(Request *req)
{
  return(fin_acc(FINISH,req));  
}