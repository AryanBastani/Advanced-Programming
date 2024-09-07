#ifndef __DOCUMENT_HPP__
#define __DOCUMENT_HPP__

#include <vector>
#include <string>

class Document 
{
public:
    Document(std::string name,int num_of_cop,int max_bor_time,int max);
    std::string get_title() { return(title); };
    bool available();
    void borrow(int current_day);
    virtual void extend(int current_day);
    void increase_copies();
    virtual int calculate_penalty(int current_day)=0;
    int calc_ret_time();
private:
    std::string title;
    int copies;
    int borrow_dur;
    int max_extend;
    int extend_count=0;
    int bor_date;
};

int find_doc(std::vector<Document*> documents,std::string document_title);

#endif