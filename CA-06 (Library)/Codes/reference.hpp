#ifndef __REFERENCE_HPP__
#define __REFERENCE_HPP__

#include <vector>
#include <string>
#include "document.hpp"

class Reference : public Document
{
public:
    Reference(std::string reference_name,int num_of_cop);
    int calculate_penalty(int current_day);
private:
};
#endif