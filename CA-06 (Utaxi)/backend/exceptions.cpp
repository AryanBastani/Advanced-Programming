#include<iostream>
#include<string>
#include"exceptions.hpp"
using namespace std;



Ut_error::Ut_error(string mass)
:runtime_error(mass),
massage(mass)
{
    
}

Not_found::Not_found()
:Ut_error(NOT_FOUND_MASS)
{

}

Empty::Empty()
:Ut_error(EMPTY_MASS)
{

}

Bad_req::Bad_req()
:Ut_error(BAD_REQ_MASS)
{

}

Permission_den::Permission_den()
:Ut_error(PERM_DEN_MASS)
{
    
}

