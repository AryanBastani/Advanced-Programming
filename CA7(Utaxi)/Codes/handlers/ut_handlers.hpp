#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "../server/server.hpp"
#include <iostream>
#include<stdexcept>
#include"../backend/utaxi.hpp"
#include"error_handlers.hpp"

class Utaxi_handler : public RequestHandler
{
  public:
    Utaxi_handler(Utaxi *the_utaxi);
  protected:
    Utaxi* utaxi;
    Response *fin_acc(int type,Request *req);

};

class Signup_handler : public Utaxi_handler 
{
  public:
    Signup_handler(Utaxi *the_utaxi);
    Response *callback(Request *);
};

class Ask_handler : public Utaxi_handler 
{
  public:
    Ask_handler(Utaxi *the_utaxi);
    Response *callback(Request *);
  private:
    Response *ask_page(int out_put,std::string without_asking);
};

class Cancel_handler : public Utaxi_handler
{
  public:
    Cancel_handler(Utaxi *the_utaxi);
    Response *callback(Request *);
};

class Show_handler : public Utaxi_handler
{
  public:
    Show_handler(Utaxi *the_utaxi,std::string sort);
    Response *callback(Request *);
  private:
    Response *show_works(std::string username);
    std::string sorted_wants;
    std::string add_head();
    std::string add_end(std::string username);
};

class Accept_handler : public Utaxi_handler
{
  public:
    Accept_handler(Utaxi *the_utaxi);
    Response *callback(Request *);
};

class Finish_handler : public Utaxi_handler
{
  public:
    Finish_handler(Utaxi *the_utaxi);
    Response *callback(Request *);
};
#endif
