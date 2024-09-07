#ifndef _ORGATE_HPP_
#define _ORGATE_HPP_

#include"Gate.hpp"

class OrGate : public Gate{
    public:
        OrGate();
        void calculateWiresVal();
        OrGate* clone() const override;
    private:
};
#endif