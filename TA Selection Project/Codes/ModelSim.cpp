#include "ModelSim.hpp"

using namespace std;

ModelSim::ModelSim(string _inputFilePath){
    inputFilePath = _inputFilePath;
}
void ModelSim::run(){
    InterfaceManager interfaceManager = InterfaceManager(inputFilePath);
    interfaceManager.readInputs();

    CmdsManager cmdsManager = CmdsManager(interfaceManager.getInputs());
    cmdsManager.runCmds();

    interfaceManager.printOutputs(cmdsManager.getOutputs());
}