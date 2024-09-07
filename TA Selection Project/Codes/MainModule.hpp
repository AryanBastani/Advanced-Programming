#ifndef _MAINMODULE_HPP_
#define _MAINMODULE_HPP_

#include"Module.hpp"

class MainModule : public Module{
    public:
        MainModule();
        int getCircuitOut(std::string circuitId);
        MainModule* clone() const override;
        void satisfyInputWireValue(std::string wireId, int newValue) override;
    private:

};

#endif