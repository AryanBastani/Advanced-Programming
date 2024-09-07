#include"Gate.hpp"

using namespace std;

Gate::Gate()
:Circuit(){

}

int Gate::calcSecondPriorityEffect(int firstPriorityEffect){
        if(firstPriorityEffect)
            return ZERO_VALUE;
        else
            return ONE_VALUE;
}

void Gate::calculateForSimpleGates(int firstPriorityVal,
    int firstPriorityEffect){

    int secondPriorityEffect = calcSecondPriorityEffect(firstPriorityEffect);
    bool inputsHaveZVal = false;

    for(int inputId = 0; inputId < inputWiers.size(); inputId++){
        int currentWireVal = inputWiers[generateInputKey(inputId)]->value;
        if(currentWireVal == firstPriorityVal){
            outputWier->value = firstPriorityEffect;
            return;
        }
        else if(currentWireVal == Z_VALUE)
            inputsHaveZVal = true;
    } 

    outputWier->value = inputsHaveZVal ? Z_VALUE : secondPriorityEffect;
    anySignalChanging = false;
}