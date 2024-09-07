#include "error_handlers.hpp"
using namespace std;


Response *find_error(Ut_error& ut_error)
{
  if(ut_error.get_mass()==EMPTY_MASS)
    return(Response::redirect("/empty"));
  else if(ut_error.get_mass()==NOT_FOUND_MASS)
    return(Response::redirect("/not_found"));
  else if(ut_error.get_mass()==PERM_DEN_MASS)
    return(Response::redirect("/perm_den"));
  else
    return(Response::redirect("/bad_req"));
}

Error_handler::Error_handler(string error_mass)
{
  mass=error_mass;
}

Response *Error_handler::callback(Request *req)
{
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  string body="";
  string line;
  ifstream before("static/before_error.html");
  while(before>>line)
    body+=line;
  body += mass;
  body +=AFTER_OUTPUT;
  res->setBody(body);
  return res;
}