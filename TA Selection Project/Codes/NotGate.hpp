#ifndef _NOTGATE_HPP_
#define _NOTGATE_HPP_

#include"Gate.hpp"

class NotGate : public Gate{
    public:
        NotGate();
        void calculateWiresVal();
        NotGate* clone() const override;
    private:
};
#endif