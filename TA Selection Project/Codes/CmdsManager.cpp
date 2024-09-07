#include"CmdsManager.hpp"

using namespace std;

CmdsManager::CmdsManager(vector<string>cmds_){
    cmds = cmds_;
    circuitsManager = CircuitsManager();
}

void CmdsManager::runTheCmd(vector<string> cmd){
    if(cmd[LINE_KEY_INDEX] == GENERATE_MOUDLE)
        handleGeneration(cmd);
    else if(cmd[LINE_KEY_INDEX] == END_MODULE)
        handleEndingGeneration(cmd);
    else if(cmd[LINE_KEY_INDEX] == ADD_MOUDLE)
        handleModuleAdding(cmd);
    else if(cmd[LINE_KEY_INDEX] == PUT_VAL_ON_WIRE)
        handlePuttingValOnWire(cmd);
    else if(cmd[LINE_KEY_INDEX] == CONNECT_WIRES)
        handleConnectingWires(cmd);
    else if(cmd[LINE_KEY_INDEX] == PRINT_OUTPUT)
        handleReceivingOutput(cmd);  
}

void CmdsManager::handleCmd(vector<string> cmd){
    try{
        runTheCmd(cmd);
    }

    catch(DuplicateModuleName& duplicateName){
        outputs.push_back(duplicateName.getMessage());
    }
    catch(DuplicateId& duplicateId){
        outputs.push_back(duplicateId.getMessage());
    }
    catch(IncompatibleInputs& incompatibleInputs){
        outputs.push_back(incompatibleInputs.getMessage());
    }
    catch(CircuitNotFound& circuitNotFound){
        outputs.push_back(circuitNotFound.getMessage());
    }
    catch(InvalidConnection& invalidConnection){
        outputs.push_back(invalidConnection.getMessage());
    }
    catch(IdNotFound& idNotFound){
        outputs.push_back(idNotFound.getMessage());
    }
    catch(InvalidValue& invalidValue){
        outputs.push_back(invalidValue.getMessage());
    }
}

void CmdsManager::runCmds(){
    for(string currentCmd : cmds){
        vector<string> currentLine = splitLine(currentCmd, CMDS_DELIMITER);
        
        handleCmd(currentLine);
    }
}

void CmdsManager::handleGeneration(vector<string> line){
    circuitsManager.generateNewModule(line[MODULE_ID_INDEX],
        stoi(line[NUM_OF_INPUTS_INDEX]));
}

void CmdsManager::handleEndingGeneration(vector<string> line){
    circuitsManager.endGeneratingModule();
}

void CmdsManager::handleModuleAdding(vector<string> line){
    circuitsManager.addCircuit(line[DEFINED_CIRCUIT_ID_INDEX],
        line[INSTANCED_CIRCUIT_ID_INDEX], getWireIds(line));
}

void CmdsManager::handlePuttingValOnWire(vector<string> line){
    circuitsManager.putValOnWire(line[WIRE_ID_INDEX], stoi(line[VALUE_INDEX]));
}

void CmdsManager::handleConnectingWires(vector<string> line){
    circuitsManager.connectWires(line[INPUT_WIRE_INDEX], line[OUTPUT_WIRE_INDEX]);
}

void CmdsManager::handleReceivingOutput(vector<string> line){
    int out = circuitsManager.getCircuitOut(line[MODULE_ID_INDEX]);
    if(out == Z_VALUE)
        outputs.push_back(ZERO_VAL_STR);
    else
        outputs.push_back(to_string(out));
}

vector<string> CmdsManager::getWireIds(vector<string> line){
    vector<string> wireIds(line.size() - WIRES_BEGIN_INDEX);

    for(int wordIndex = WIRES_BEGIN_INDEX; wordIndex < line.size(); wordIndex++)
        wireIds[wordIndex - WIRES_BEGIN_INDEX] = line[wordIndex];

    return wireIds;
}

vector<string> CmdsManager::splitLine(string line, char delimiter){
    vector<string> spiliteds;
    string currentWord;

    for(int charId=0;charId<(int)line.size();charId++){
        if(line[charId]==delimiter){
            spiliteds.push_back(currentWord);
            currentWord="";
        }
        else
            currentWord+=line[charId];
    }
    spiliteds.push_back(currentWord);

    return(spiliteds);
}