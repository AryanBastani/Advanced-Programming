#ifndef __MY_SERVER__
#define __MY_SERVER__

#include "../server/server.hpp"
#include "../backend/utaxi.hpp"
#include "../handlers/ut_handlers.hpp"

class My_server : public Server {
public:
  My_server(int port = 5000);

};
void show_server(My_server server,Utaxi* utaxi);
void start_server(char *argv[]);
#endif
