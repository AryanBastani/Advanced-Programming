#ifndef _CIRCUITS_HPP_
#define _CIRCUITS_HPP_

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include"Wire.hpp"

const std::string INPUT_KEY_PREFIX = "in";
const std::string OUTPUT_KEY = "out";

class Circuit{
    public:
        Circuit();
        virtual void satisfyInputWireValue(std::string wireId, int value);
        virtual void calculateWiresVal() = 0;
        int getOutput();
        void generateInputs(int numOfInputs);
        virtual Circuit* clone() const=0;
        void beCloned(std::unordered_map<std::string, Wire*> _inputWiers,
            Wire* _outputWier, bool _anySignalChanging);
        
    protected:
        std::unordered_map<std::string, Wire*> inputWiers;
        Wire* outputWier;
        bool anySignalChanging;
        std::unordered_map<std::string, Wire*> cloneWireMap(
            std::unordered_map<std::string, Wire*> map);

        std::string generateInputKey(int inputId);

    private:
        void initializeOutputWire();
        
        
};
#endif