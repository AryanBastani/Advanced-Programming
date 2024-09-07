#include"AndGate.hpp"

using namespace std;

AndGate::AndGate()
:Gate(){
    
}

void AndGate::calculateWiresVal(){
    calculateForSimpleGates(ZERO_VALUE, ZERO_VALUE);
}

AndGate* AndGate::clone() const {
    AndGate* andGate = new AndGate();
    andGate->beCloned(inputWiers, outputWier, anySignalChanging);
    return andGate;
}