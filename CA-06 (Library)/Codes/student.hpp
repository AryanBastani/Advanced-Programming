#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <vector>
#include <string>
#include "member.hpp"

class Student : public Member
{
public:
    Student(std::string student_id,std::string name);
private:
    std::string id;
};

#endif