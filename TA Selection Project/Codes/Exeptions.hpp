#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__
#include<iostream>
#include<string>
#include<stdexcept>


class ModelSimError : public std::runtime_error
{
    public:
        ModelSimError(std::string _message);
        std::string getMessage() { return(message); };
    private:
        std::string message;
};

class DuplicateModuleName : public ModelSimError
{
    public:
        DuplicateModuleName();
    private:
};

class DuplicateId : public ModelSimError
{
    public:
        DuplicateId();
    private:
};

class IncompatibleInputs : public ModelSimError
{
    public:
        IncompatibleInputs();
    private:
};

class CircuitNotFound : public ModelSimError
{
    public:
        CircuitNotFound();
    private:
};

class InvalidConnection : public ModelSimError
{
    public:
        InvalidConnection();
    private:
};

class IdNotFound : public ModelSimError
{
    public:
        IdNotFound();
    private:
};

class InvalidValue : public ModelSimError
{
    public:
        InvalidValue();
    private:
};
#endif