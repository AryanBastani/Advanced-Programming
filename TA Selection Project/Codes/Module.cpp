#include"Module.hpp"

using namespace std;


Module::Module()
:Circuit(){
    addGatesToDefineds();
}

void Module::addGatesToDefineds(){
    definedCircuits[AND_GATE_ID] = new AndGate();
    definedCircuits[OR_GATE_ID] = new OrGate();
    definedCircuits[NOT_GATE_ID] = new NotGate();
    definedCircuits[XOR_GATE_ID] = new XorGate();
    definedCircuits[NAND_GATE_ID] = new NandGate();
    definedCircuits[NOR_GATE_ID] = new NorGate();
}

void Module::addDefinedCircuit(string id, Circuit* circuit){
    definedCircuits[id] = circuit->clone();
}

void Module::addWires(vector<string> wireIds){
    for(string currentWireId : wireIds)
        middleWiers[currentWireId] = new Wire();
}

void Module::addInnerCircuit(string definedCircuitId,
    string innerCircuitId, vector<string> wireIds){

    innerCircuits[innerCircuitId] = new InnerCircuit();
    innerCircuits[innerCircuitId]->theCircuit = definedCircuits[definedCircuitId]->clone();
    innerCircuits[innerCircuitId]->theCircuit->generateInputs(wireIds.size() - 1);
    
    addWires(wireIds);

    innerCircuits[innerCircuitId]->inputIds = wireIds;
    innerCircuits[innerCircuitId]->inputIds.pop_back();

    innerCircuits[innerCircuitId]->outputId = wireIds.back();
}

Wire* Module::findWire(string id){
    if((id == OUTPUT_KEY) && (outputWier != NO_OUTPUT))
        return outputWier;
    auto got = inputWiers.find(id);
    if(got == inputWiers.end())
        return middleWiers[id];
    return got->second;

}

void Module::connectWires(string inputId, string outputId){
    Wire* outputWier = findWire(outputId);

    outputWier->inputId = inputId;
}

void Module::satisfyMiddleWire(string wireId){
    Wire* theWire = middleWiers[wireId];

    if(theWire->inputId == HAS_NOT_INPUT)
        return;
    
    int oldVal = theWire->value;
    int newVal = findWire(theWire->inputId)->value;
    if(oldVal != newVal)
        anySignalChanging = true;
    theWire->value = newVal;
}

void Module::satisfyInnerInputs(string innerId){
    InnerCircuit* innerCircuit = innerCircuits[innerId];
    vector<string> inputIds = innerCircuit->inputIds;
    for(int inputIndex = 0; inputIndex < inputIds.size(); inputIndex++){

        Wire* currentWire = middleWiers[inputIds[inputIndex]];
        satisfyMiddleWire(inputIds[inputIndex]);
        innerCircuit->theCircuit->
            satisfyInputWireValue(INPUT_KEY_PREFIX + to_string(inputIndex), currentWire->value);
    }
}
void Module::updateOutputVal(){
    if(outputWier->inputId == HAS_NOT_INPUT)
        return;

    int oldVal = outputWier->value;
    int newVal = findWire(outputWier->inputId)->value;
    if(oldVal != newVal)
        anySignalChanging = true;

    outputWier->value = newVal;
}

void Module::calculateWiresVal(){
    anySignalChanging = true;
    while(anySignalChanging){
        anySignalChanging = false;
        for(auto currentInner : innerCircuits){
            string currentInnerId = currentInner.first;
            satisfyInnerInputs(currentInnerId);
            Circuit* currentCircuit = innerCircuits[currentInnerId]->theCircuit;
            currentCircuit->calculateWiresVal();
            Wire* CurrentOutWire = middleWiers[innerCircuits[currentInnerId]->outputId];
            CurrentOutWire->value = currentCircuit->getOutput();
        }
        updateOutputVal();
    }
}

unordered_map<string, InnerCircuit*> Module::cloneInnerMap(
    unordered_map<string, InnerCircuit*> map){

    unordered_map<string, InnerCircuit*> newMap;
    for(auto currentElement : map)
        newMap[currentElement.first] = currentElement.second->clone();
        
    return newMap;
}

unordered_map<string, Circuit*> Module::cloneCircuitMap(
    unordered_map<string, Circuit*> map){

    unordered_map<string, Circuit*> newMap;
    for(auto currentElement : map)
        newMap[currentElement.first] = currentElement.second->clone();
        
    return newMap;
}

void Module::beCloned(unordered_map<string, Wire*> _inputWiers,
    Wire* _outputWier, bool _anySignalChanging,
    unordered_map<string, InnerCircuit*> _innerCircuits,
    unordered_map<string, Wire*> _middleWiers,
    unordered_map<string, Circuit*> _definedCircuits){

    Circuit::beCloned(_inputWiers, _outputWier, _anySignalChanging);

    innerCircuits = cloneInnerMap(_innerCircuits);
    middleWiers = Circuit::cloneWireMap(_middleWiers);
    definedCircuits = cloneCircuitMap(_definedCircuits);
}

bool Module::hasThisId(string id, int definedsOrInners){
    if(definedsOrInners == DEFINED_CIRCUITS)
        return (definedCircuits.find(id) != definedCircuits.end());
    return (innerCircuits.find(id) != innerCircuits.end());
}