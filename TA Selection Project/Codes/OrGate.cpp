#include"OrGate.hpp"

using namespace std;

OrGate::OrGate()
:Gate(){
    
}

void OrGate::calculateWiresVal(){
    calculateForSimpleGates(ONE_VALUE, ONE_VALUE);
}

OrGate* OrGate::clone() const {
    OrGate* orGate = new OrGate();
    orGate->beCloned(inputWiers, outputWier, anySignalChanging);
    return orGate;
}