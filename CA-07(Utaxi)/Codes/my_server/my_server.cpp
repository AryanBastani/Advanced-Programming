#include "my_server.hpp"

My_server::My_server(int port) : Server(port) {}

void show_server(My_server server,Utaxi* utaxi)
{
    server.get("/",new ShowPage("static/home.html"));
    server.get("/signup",new ShowPage("static/signup.html"));
    server.post("/signup",new Signup_handler(utaxi));
    server.get("/ask_trip",new ShowPage("static/ask_trip.html"));
    server.post("/ask_trip",new Ask_handler(utaxi));
    server.get("/cancel_trip",new ShowPage("static/cancel_trip.html"));
    server.post("/cancel_trip",new Cancel_handler(utaxi));
    server.get("/before_show",new ShowPage("static/before_show.html"));
    server.post("/show_trips",new Show_handler(utaxi,NO));
    server.post("/show_sorted",new Show_handler(utaxi,YES));
    server.post("/accept",new Accept_handler(utaxi));
    server.post("/finish",new Finish_handler(utaxi));
    server.get("/done",new ShowPage("static/done.html"));
    server.get("/empty",new Error_handler("Empty!"));
    server.get("/bad_req",new Error_handler("Bad request!"));
    server.get("/perm_den",new Error_handler("Permision denied!"));
    server.get("/not_found",new Error_handler("Not found!"));
    server.setNotFoundErrPage("static/404.html");
    server.run();
}

void start_server(char *argv[])
{
    Utaxi* utaxi=new Utaxi();
    utaxi->read_locations(argv);
    My_server server(5000);

    show_server(server,utaxi);
}
