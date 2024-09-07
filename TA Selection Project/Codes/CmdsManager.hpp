#ifndef _CMDSMANAGER_HPP_
#define _CMDSMANAGER_HPP_

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>

#include"CircuitsManager.hpp"

class CmdsManager{
    public:
        CmdsManager(std::vector<std::string> cmds_);
        void runCmds();
        std::vector<std::string> getOutputs() { return outputs; };
        
    private:
        std::vector<std::string> cmds;
        std::vector<std::string> outputs;
        CircuitsManager circuitsManager;

        std::vector<std::string> splitLine(std::string line, char delimiter);
        void handleGeneration(std::vector<std::string> line);
        void handleEndingGeneration(std::vector<std::string> line);
        void handleModuleAdding(std::vector<std::string> line);
        void handlePuttingValOnWire(std::vector<std::string> line);
        void handleConnectingWires(std::vector<std::string> line);
        void handleReceivingOutput(std::vector<std::string> line);
        std::vector<std::string> getWireIds(std::vector<std::string> line);
        void handleCmd(std::vector<std::string> cmd);
        void runTheCmd(std::vector<std::string> cmd);

        const std::string GENERATE_MOUDLE = "new_module";
        const std::string END_MODULE = "end_module";
        const std::string ADD_MOUDLE = "add";
        const std::string PUT_VAL_ON_WIRE = "put";
        const std::string CONNECT_WIRES = "connect";
        const std::string PRINT_OUTPUT = "print";
        const char CMDS_DELIMITER = ' ';
        const int LINE_KEY_INDEX = 0;
        const int MODULE_ID_INDEX = 1;
        const int NUM_OF_INPUTS_INDEX = 2;
        const int DEFINED_CIRCUIT_ID_INDEX = 1;
        const int INSTANCED_CIRCUIT_ID_INDEX = 2;
        const int WIRES_BEGIN_INDEX = 3;
        const int WIRE_ID_INDEX = 1;
        const int VALUE_INDEX = 2;
        const int INPUT_WIRE_INDEX = 1;
        const int OUTPUT_WIRE_INDEX = 2;
        const std::string ZERO_VAL_STR = "z";

};

#endif