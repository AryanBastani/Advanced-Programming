#ifndef _ERROR_HANDLERS_
#define _ERROR_HANDLERS_

#include "../server/server.hpp"
#include <iostream>
#include <stdexcept>
#include"../backend/utaxi.hpp"

const std::string AFTER_OUTPUT=R"(</h1><br><br><br><form action="/" method=
"get"><input type="submit" value="Go home"></input></form>
</body></html></div></body></html>)";

class Error_handler : public RequestHandler
{
  public:
    Error_handler(std::string error_mass);
    Response *callback(Request *);
  private:
    std:: string mass;
};
Response *find_error(Ut_error& ut_error);
#endif