#ifndef _NORGATE_HPP_
#define _NORGATE_HPP_

#include"Gate.hpp"

class NorGate : public Gate{
    public:
        NorGate();
        void calculateWiresVal();
        NorGate* clone() const override;
    private:
};
#endif