#ifndef __MAGAZINE_HPP__
#define __MAGAZINE_HPP__

#include <vector>
#include <string>
#include "document.hpp"

class Magazine : public Document
{
public:
    Magazine(std::string magazine_title,int pub_year,int num,int copies);
    void extend(int current_day);
    int calculate_penalty(int current_day);
private:
    int year;
    int number;
};

#endif