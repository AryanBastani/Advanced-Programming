#include"XorGate.hpp"

using namespace std;

XorGate::XorGate()
:Gate(){
    
}

void XorGate::calculateWiresVal(){
    int numOfOneVals = 0;

    for(int inputId = 0; inputId < inputWiers.size(); inputId++){
        int currentWireVal = inputWiers[generateInputKey(inputId)]->value;
        if(currentWireVal == Z_VALUE){
            outputWier->value = Z_VALUE;
            return;
        }
        else if(currentWireVal == ONE_VALUE)
            numOfOneVals++;
    } 
    
    outputWier->value = ((numOfOneVals%2) == 1) ? ONE_VALUE : ZERO_VALUE;
    anySignalChanging = false;
}

XorGate* XorGate::clone() const {
    XorGate* xorGate = new XorGate();
    xorGate->beCloned(inputWiers, outputWier, anySignalChanging);
    return xorGate;
}