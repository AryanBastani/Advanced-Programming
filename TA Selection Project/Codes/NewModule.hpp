#ifndef _NEWMODULE_HPP_
#define _NEWMODULE_HPP_

#include"Module.hpp"

class NewModule : public Module{
    public:
        NewModule();
        NewModule* clone() const override;

    private:
    

};

#endif