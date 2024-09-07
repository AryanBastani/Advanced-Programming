#include"NandGate.hpp"

using namespace std;

NandGate::NandGate()
:Gate(){
    
}

void NandGate::calculateWiresVal(){
    calculateForSimpleGates(ZERO_VALUE, ONE_VALUE);
}

NandGate* NandGate::clone() const {
    NandGate* nandGate = new NandGate();
    nandGate->beCloned(inputWiers, outputWier, anySignalChanging);
    return nandGate;
}