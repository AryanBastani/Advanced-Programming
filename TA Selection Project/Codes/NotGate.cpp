#include"NotGate.hpp"

NotGate::NotGate()
:Gate(){

}


void NotGate::calculateWiresVal(){
    int inputVal = inputWiers[generateInputKey(0)]->value;

    outputWier->value = (inputVal == Z_VALUE) ?
        Z_VALUE : inputVal ? ZERO_VALUE : ONE_VALUE;
    
    anySignalChanging = false;
}

NotGate* NotGate::clone() const {
    NotGate* notGate = new NotGate();
    notGate->beCloned(inputWiers, outputWier, anySignalChanging);
    return notGate;
}
