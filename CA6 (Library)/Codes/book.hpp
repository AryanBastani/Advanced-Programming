#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#include <vector>
#include <string>
#include "document.hpp"

class Book : public Document
{
public:
    Book(std::string name,int num_of_cop);
    int calculate_penalty(int current_day);
private:
};

#endif