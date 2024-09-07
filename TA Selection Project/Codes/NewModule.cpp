#include"NewModule.hpp"

NewModule::NewModule()
: Module(){

}

NewModule* NewModule::clone() const {
    NewModule* newModule = new NewModule();
    newModule->beCloned(inputWiers, outputWier, anySignalChanging,
        innerCircuits, middleWiers, definedCircuits);
        
    return newModule;
}
