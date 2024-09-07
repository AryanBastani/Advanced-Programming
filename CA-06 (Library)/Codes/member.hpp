#ifndef __MEMBER_HPP__
#define __MEMBER_HPP__

#include <vector>
#include <string>
#include "book.hpp"
#include "magazine.hpp"
#include "reference.hpp"

class Member 
{
public:
    Member(std::string member_name,int max);
    bool same_name(std::string new_name);
    std::string get_name() { return(name); };
    bool bor_count_check();
    void borrow_doc(Document* document,int current_day);
    void extend_doc(int current_day,std::string doc_title);
    int return_doc(int current_day,std::string doc_title);
    int total_penalty(int current_day);
private:
    std::string name;
    std::vector<Document*> borrowed;
    int max_borrow;
    int perv_penalty=0;
};

#endif