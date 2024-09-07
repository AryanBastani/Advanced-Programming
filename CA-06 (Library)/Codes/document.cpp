#include<iostream>
#include<string>
#include<vector>
#include"document.hpp"
using namespace std;

const string SAME_DAY_EXTEND="You can’t extend and borrow a document on the same day";
const string LATE_RENEW_MASS="You can’t renew a document after receiving a penalty";
const string MORE_THAN_MAX="You can’t renew a document more than two times";

Document::Document(string name,int num_of_cop,int max_bor_time,int max)
{
    title=name;
    copies=num_of_cop;
    borrow_dur=max_bor_time;
    max_extend=max;
}

bool Document::available()
{
    return(copies>0);
}

void Document::borrow(int current_day)
{
    copies--;
    bor_date=current_day;
}

int find_doc(vector<Document*> documents,string document_title)
{
    for(int document_id=0;document_id<documents.size();document_id++)
    {
        if(documents[document_id]->get_title()==document_title)
            return(document_id);
    }
    return(-1);
}

int Document::calc_ret_time()
{
    return(bor_date+(1+extend_count)*borrow_dur);
}

void Document::extend(int current_day)
{
    if(bor_date==current_day)
        cout<<SAME_DAY_EXTEND<<'\n';
    else if(current_day>calc_ret_time())
        cout<<LATE_RENEW_MASS<<'\n';
    else if(extend_count==max_extend)
        cout<<MORE_THAN_MAX<<'\n';
    else
    {
        extend_count++;
        return;
    }
    exit(EXIT_SUCCESS);
}

void Document::increase_copies()
{
    copies++;
}
