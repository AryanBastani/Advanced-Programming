#ifndef _INTERFACEMANAGER_HPP_
#define _INTERFACEMANAGER_HPP_

#include<iostream>
#include<vector>
#include<string>
#include <fstream> 

class InterfaceManager{
    public:
        InterfaceManager(std::string inputFilePath);
        void readInputs();
        std::vector<std::string> getInputs() { return inputs; };
        void printOutputs(std::vector<std::string> outputs);
    private:
        std::ifstream inputFile;
        std::vector<std::string> inputs;

        void printOutVal(std::string outVal);
        
};

#endif