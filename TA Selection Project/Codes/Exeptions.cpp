#include"Exeptions.hpp"

using namespace std;

const std::string DUPLICATE_MODULE_NAME_MSG = "this module already exists";
const std::string DUPLICATE_ID_MSG = "duplicate ID";
const std::string INCOMPATIBLE_INPUTS_MSG = "incompatible inputs";
const std::string CIRCUIT_NOT_FOUND_MSG = "gate/module not found";
const std::string INVALID_CONNECTION_MSG = "invalid connection";
const std::string ID_NOT_FOUND = "ID not found";
const std::string INVALID_VALUE_MSG = "value not valid";

ModelSimError::ModelSimError(string _message)
:runtime_error(_message),
message(_message)
{
    
}

DuplicateModuleName::DuplicateModuleName()
:ModelSimError(DUPLICATE_MODULE_NAME_MSG){

}


DuplicateId::DuplicateId()
:ModelSimError(DUPLICATE_ID_MSG){

}


IncompatibleInputs::IncompatibleInputs()
:ModelSimError(INCOMPATIBLE_INPUTS_MSG){

}   

CircuitNotFound::CircuitNotFound()
:ModelSimError(CIRCUIT_NOT_FOUND_MSG){

}


InvalidConnection::InvalidConnection()
:ModelSimError(INVALID_CONNECTION_MSG){

}

IdNotFound::IdNotFound()
:ModelSimError(ID_NOT_FOUND){

}

InvalidValue::InvalidValue()
:ModelSimError(INVALID_VALUE_MSG){

}