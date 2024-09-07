#include"CircuitsManager.hpp"

using namespace std;


CircuitsManager::CircuitsManager(){
    mainCircuit = new MainModule();
    currentModule = mainCircuit;
}

void CircuitsManager::connectWires(std::string inputId, std::string outputId){
    currentModule->connectWires(inputId, outputId);
}

void CircuitsManager::addCircuit(string definedCircuitId,
    string instancedCircuitId, vector<string> wireIds){
    if(currentModule->hasThisId(instancedCircuitId, INNER_CIRCUITS))
        throw DuplicateId(); 
    currentModule->addInnerCircuit(definedCircuitId, instancedCircuitId, wireIds);
}

void CircuitsManager::generateNewModule(string moduleId, int numOfInputs){
    if(currentModule->hasThisId(moduleId, DEFINED_CIRCUITS))
        throw DuplicateModuleName();
    
    InGeneratingModule* newModule = new InGeneratingModule();
    newModule->theModule = new NewModule();
    newModule->id = moduleId;
    newModule->theModule->generateInputs(numOfInputs);

    inGeneratingCircuits.push(newModule);

    currentModule = newModule->theModule;
}

void CircuitsManager::endGeneratingModule(){
    InGeneratingModule* toBeAddedModule = inGeneratingCircuits.top();
    inGeneratingCircuits.pop();

    if(inGeneratingCircuits.empty())
        currentModule = mainCircuit;
    else
        currentModule = inGeneratingCircuits.top()->theModule;

    currentModule->addDefinedCircuit(toBeAddedModule->id, toBeAddedModule->theModule);
}

void CircuitsManager::putValOnWire(string wireId, int value){
    currentModule->satisfyInputWireValue(wireId, value);
}

int CircuitsManager::getCircuitOut(string circuitId){
    return mainCircuit->getCircuitOut(circuitId);
}