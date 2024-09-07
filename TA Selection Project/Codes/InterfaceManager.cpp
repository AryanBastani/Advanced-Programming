#include"InterfaceManager.hpp"

using namespace std;



InterfaceManager::InterfaceManager(string inputFilePath){
    inputFile = ifstream(inputFilePath);
}

void InterfaceManager::readInputs(){
    string line;

    while(getline(inputFile, line))
        inputs.push_back(line);
}

void InterfaceManager::printOutVal(string outVal){
        cout << outVal << '\n';
}

void InterfaceManager::printOutputs(vector<string> outputs){
    for(string currentOut : outputs)
        printOutVal(currentOut);
}
