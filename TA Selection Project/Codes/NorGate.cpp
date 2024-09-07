#include"NorGate.hpp"

using namespace std;

NorGate::NorGate()
:Gate(){
    
}

void NorGate::calculateWiresVal(){
    calculateForSimpleGates(ONE_VALUE, ZERO_VALUE);
}

NorGate* NorGate::clone() const {
    NorGate* norGate = new NorGate();
    norGate->beCloned(inputWiers, outputWier, anySignalChanging);
    return norGate;
}