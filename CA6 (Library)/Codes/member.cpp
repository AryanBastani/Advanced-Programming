#include"member.hpp"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const string NO_BORROW_MASS="You have not borrowed this document";
const string TOO_MUCH_BOR="Maximum number of allowed borrows exceeded";
const string AGAIN_BOR_MASS="This document does not exist";

Member::Member(string member_name,int max)
{
    name=member_name;
    max_borrow=max;
}

bool Member::same_name(string new_name)
{
    return(new_name==name);
}

bool Member::bor_count_check()
{
    return(borrowed.size()<max_borrow);
}

void Member::borrow_doc(Document* document,int current_day)
{
    if(!bor_count_check())
    {
        cout<<TOO_MUCH_BOR<<'\n';
    }
    else if(find_doc(borrowed,document->get_title())!=-1)
    {
        cout<<AGAIN_BOR_MASS<<'\n';
    }
    else
    {
        borrowed.push_back(document);
        document->borrow(current_day);
        return;
    }
    exit(EXIT_SUCCESS);
}

void Member::extend_doc(int current_day,string doc_title)
{
    int doc_id=find_doc(borrowed,doc_title);
    if(doc_id==-1)
    {
        cout<<NO_BORROW_MASS<<'\n';
        exit(EXIT_SUCCESS);
    }
    else
        borrowed[doc_id]->extend(current_day);
}

int Member::return_doc(int current_day,string doc_title)
{
    int doc_id=find_doc(borrowed,doc_title);
    if(doc_id==-1)
    {
        cout<<NO_BORROW_MASS<<'\n';
        exit(EXIT_SUCCESS);
    }
    else
    {
        perv_penalty+=borrowed[doc_id]->calculate_penalty(current_day);
        borrowed.erase(borrowed.begin()+doc_id);
        return(doc_id);
    }
    return(-1);
}

int Member::total_penalty(int current_day)
{
    int penalty=0;
    for(int doc_id=0;doc_id<borrowed.size();doc_id++)
    {
        penalty+=borrowed[doc_id]->calculate_penalty(current_day);
    }
    penalty+=perv_penalty;
    return(penalty);
}