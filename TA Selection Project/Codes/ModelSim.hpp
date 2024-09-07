#ifndef _MODELSIM_HPP_
#define _MODELSIM_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include "InterfaceManager.hpp"
#include "CmdsManager.hpp"

class ModelSim{
    public:
        ModelSim(std::string _inputFilePath);
        void run();
    private:
        std::string inputFilePath;
};

#endif