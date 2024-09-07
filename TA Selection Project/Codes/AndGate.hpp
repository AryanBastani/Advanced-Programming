#ifndef _ANDGATE_HPP_
#define _ANDGATE_HPP_

#include"Gate.hpp"

class AndGate : public Gate{
    public:
        AndGate();
        void calculateWiresVal();
        AndGate* clone() const override;
    private:
};
#endif