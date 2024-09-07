#ifndef _MODULE_HPP_
#define _MODULE_HPP_
#include"AndGate.hpp"
#include"OrGate.hpp"
#include"NotGate.hpp"
#include"XorGate.hpp"
#include"NandGate.hpp"
#include"NorGate.hpp"
#include"Circuit.hpp"

const int INNER_CIRCUITS = 0;
const int DEFINED_CIRCUITS = 1;

struct InnerCircuit{
        std::vector<std::string> inputIds; 
        Circuit* theCircuit;
        std::string outputId;

        InnerCircuit* clone(){
            InnerCircuit* newInner = new InnerCircuit();
            newInner->inputIds = inputIds;
            newInner->theCircuit = theCircuit->clone();
            newInner->outputId = outputId;

            return newInner;
        }
    };

class Module : public Circuit{

    
    public:
        Module();
        void addInnerCircuit(std::string definedCircuitId,
            std::string innerCircuitId, std::vector<std::string> wireIds);
        void addDefinedCircuit(std::string id, Circuit* circuit);
        void connectWires(std::string inputId, std::string outputId);
        void calculateWiresVal();
        void beCloned(std::unordered_map<std::string, Wire*> _inputWiers,
            Wire* _outputWier, bool _anySignalChanging,
            std::unordered_map<std::string, InnerCircuit*> _innerCircuits,
            std::unordered_map<std::string, Wire*> _middleWiers,
            std::unordered_map<std::string, Circuit*> _definedCircuits);
        bool hasThisId(std::string id, int definedsOrInners);

    protected:
        std::unordered_map<std::string, InnerCircuit*> innerCircuits;
        std::unordered_map<std::string, Wire*> middleWiers;
        std::unordered_map<std::string, Circuit*> definedCircuits;
        
        Wire* findWire(std::string id);


    private:
        const std::string AND_GATE_ID = "and";
        const std::string OR_GATE_ID = "or";
        const std::string NOT_GATE_ID = "not";
        const std::string XOR_GATE_ID = "xor";
        const std::string NAND_GATE_ID = "nand";
        const std::string NOR_GATE_ID = "nor";
        const Wire* NO_OUTPUT = 0;

        void addGatesToDefineds();
        void addWires(std::vector<std::string> wireIds);
        void satisfyMiddleWire(std::string wireId);
        std::unordered_map<std::string, InnerCircuit*> cloneInnerMap(std::unordered_map<std::string, InnerCircuit*> map);
        std::unordered_map<std::string, Circuit*> cloneCircuitMap(std::unordered_map<std::string, Circuit*>);
        void satisfyInnerInputs(std::string innerId);
        void updateOutputVal();
};

#endif