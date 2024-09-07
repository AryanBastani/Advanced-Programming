#ifndef _XorGate_HPP_
#define _XorGate_HPP_

#include"Gate.hpp"

class XorGate : public Gate{
    public:
        XorGate();
        void calculateWiresVal();
        XorGate* clone() const override;
    private:
};
#endif