#ifndef _CIRCUITSMANAGER_HPP_
#define _CIRCUITSMANAGER_HPP_

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>

#include"MainModule.hpp"
#include"NewModule.hpp"



class CircuitsManager{
    struct InGeneratingModule{
    std::string id;
    NewModule* theModule;
    };
    public:
        CircuitsManager();
        void connectWires(std::string inputId, std::string outputId);
        void addCircuit(std::string definedCircuitId,
            std::string instancedCircuitId, std::vector<std::string> wireIds);
        void generateNewModule(std::string moduleId, int numOfInputs);
        void putValOnWire(std::string wireId, int value);
        int getCircuitOut(std::string circuitId);
        void endGeneratingModule();

    private:
        MainModule* mainCircuit;
        std::stack<InGeneratingModule*> inGeneratingCircuits;
        Module* currentModule;
};
#endif