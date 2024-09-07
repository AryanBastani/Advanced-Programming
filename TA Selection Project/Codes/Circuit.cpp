#include"Circuit.hpp"

using namespace std;

Circuit::Circuit(){
    initializeOutputWire();
    anySignalChanging = true;
}

void Circuit::satisfyInputWireValue(string wireId, int newValue){
    if(newValue != inputWiers[wireId]->value)
        anySignalChanging = true;
    inputWiers[wireId]->value = newValue;
}

string Circuit::generateInputKey(int inputId){
    return INPUT_KEY_PREFIX + to_string(inputId);
}

void Circuit::generateInputs(int numOfInputs){
    for(int inputId = 0; inputId < numOfInputs; inputId++)
        inputWiers[generateInputKey(inputId)] = new Wire();
}

void Circuit::initializeOutputWire(){
    outputWier = new Wire();
}

int Circuit::getOutput(){
    if(anySignalChanging)
        calculateWiresVal();
    return outputWier->value;
}

unordered_map<string, Wire*> Circuit::cloneWireMap(
    unordered_map<string, Wire*> map){

    unordered_map<string, Wire*> newMap;
    for(auto currentElement : map)
        newMap[currentElement.first] = currentElement.second->clone();
        
    return newMap;
}

void Circuit::beCloned(unordered_map<string, Wire*> _inputWiers,
            Wire* _outputWier, bool _anySignalChanging){
    inputWiers = cloneWireMap(_inputWiers);
    outputWier = _outputWier->clone();
    anySignalChanging = _anySignalChanging;
}
