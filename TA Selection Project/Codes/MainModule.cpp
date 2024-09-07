#include"MainModule.hpp"

using namespace std;

MainModule::MainModule()
: Module(){

}

void MainModule::satisfyInputWireValue(string wireId, int newValue){
    Wire* theWire = findWire(wireId);
    if(theWire->value != newValue)
        anySignalChanging = true;
        
    theWire->value = newValue;
}

int MainModule::getCircuitOut(string circuitId){
    if(anySignalChanging)
        calculateWiresVal();
    return innerCircuits[circuitId]->theCircuit->getOutput();
}

MainModule* MainModule::clone() const {
    MainModule* mainModule = new MainModule();
    mainModule->beCloned(inputWiers, outputWier, anySignalChanging,
        innerCircuits, middleWiers, definedCircuits);

    return mainModule;
}


