#ifndef _GATE_HPP_
#define _GATE_HPP_

#include"Circuit.hpp"

class Gate : public Circuit{
    public:
        Gate();

    protected:
        void calculateForSimpleGates(int firstPriorityVal,
        int firstPriorityEffect);
        int calcSecondPriorityEffect(int firstPriorityEffect);

    private:
};


#endif