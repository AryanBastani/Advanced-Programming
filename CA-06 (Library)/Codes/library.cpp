#include"library.hpp"
#include<iostream>
using namespace std;

const string NOT_UNIQ_MEM="Name already exists";
const string NOT_UNIQ_DOC="A document with the specified name already exists";
const string INVALID_NUM_MASS="Invalid number";
const string INVALID_YEAR_MASS="Invalid year";
const string NO_DOCUMENT="This document does not exist";

void Library::time_pass(int days)
{
    current_day+=days;
}

bool Library::unique_member(string new_name)
{
    for(int member_id=0;member_id<members.size();member_id++)
    {
        if(members[member_id]->get_name()==new_name)
        {
            cout<<NOT_UNIQ_MEM<<'\n';
            exit(EXIT_SUCCESS);
            return(false);
        }

    }
    return(true);
}

bool Library::unique_document(string new_name)
{
    for(int document_id=0;document_id<documents.size();document_id++)
    {
        if(documents[document_id]->get_title()==new_name)
        {
            cout<<NOT_UNIQ_DOC<<'\n';
            exit(EXIT_SUCCESS);
            return(false);
        }
    }
    return(true);
}

void Library::add_student_member(string student_id,string student_name)
{
    if(unique_member(student_name))
        members.push_back(new Student(student_id,student_name));
}

void Library::add_prof_member(string prof_name)
{
    if(unique_member(prof_name))
        members.push_back(new Professor(prof_name));
}

void Library::add_book(string book_title, int copies)
{
    if(unique_document(book_title))
        documents.push_back(new Book(book_title,copies));
}

void Library::add_reference(string reference_title, int copies)
{
    if(unique_document(reference_title))
        documents.push_back(new Reference(reference_title,copies));
}

void Library::numbers_check(int year,int number)
{
    if(number<=0)
        cout<<INVALID_NUM_MASS<<'\n';
    else if(year<=0)
        cout<<INVALID_YEAR_MASS<<'\n';
    else
        return;
    exit(EXIT_SUCCESS);
}

void Library::add_magazine(string magazine_title, int year, int number, int copies)
{
    numbers_check(year,number);

    if(unique_document(magazine_title))
        documents.push_back(new Magazine(magazine_title,year,number,copies));
}

int Library::find_member(string member_name)
{
    for(int member_id=0;member_id<members.size();member_id++)
    {
        if(members[member_id]->get_name()==member_name)
            return(member_id);
    }
    return(-1);
}

void Library::borrow(string member_name,string document_title)
{
    int member_id=find_member(member_name);
    int doc_id=find_doc(documents,document_title);

    if(doc_id!=-1&&documents[doc_id]->available())
        members[member_id]->borrow_doc(documents[doc_id],current_day);
    else
    {
        cout<<NO_DOCUMENT<<'\n';
        exit(EXIT_SUCCESS);
    }
}

void Library::extend(string member_name,string document_title)
{
    int member_id=find_member(member_name);
    members[member_id]->extend_doc(current_day,document_title);
}

void Library::return_document(string member_name,string document_title)
{
    int member_id=find_member(member_name);
    int document_id=members[member_id]->return_doc(current_day,document_title);
    if(document_id!=-1)
        documents[document_id]->increase_copies();
}

int Library::get_total_penalty(string member_name)
{
    return(members[find_member(member_name)]->total_penalty(current_day));
}

vector<string> Library::available_titles()
{
    vector<string> titles;
    for(int doc_id=0;doc_id<documents.size();doc_id++)
    {
        if(documents[doc_id]->available()) 
            titles.push_back(documents[doc_id]->get_title());
    }
    return(titles);
}