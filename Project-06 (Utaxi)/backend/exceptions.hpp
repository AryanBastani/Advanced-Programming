#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__
#include<iostream>
#include<string>
#include<stdexcept>

const std::string NOT_FOUND_MASS="Not Found";
const std::string EMPTY_MASS="EMPTY";
const std::string BAD_REQ_MASS="Bad Request";
const std::string PERM_DEN_MASS="Permission Denied";

class Ut_error : public std::runtime_error
{
    public:
        Ut_error(std::string mass);
        std::string get_mass() { return(massage); };
    private:
        std::string massage;
};

class Not_found : public Ut_error
{
    public:
        Not_found();
    private:
};

class Empty : public Ut_error
{
    public:
        Empty();
    private:
};

class Bad_req : public Ut_error
{
    public:
        Bad_req();
    private:
};

class Permission_den : public Ut_error
{
    public:
        Permission_den();
    private:
};
#endif