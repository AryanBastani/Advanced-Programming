#ifndef _NANDGATE_HPP_
#define _NANDGATE_HPP_

#include"Gate.hpp"

class NandGate : public Gate{
    public:
        NandGate();
        void calculateWiresVal();
        NandGate* clone() const override;
    private:
};
#endif