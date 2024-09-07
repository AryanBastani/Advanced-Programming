#include<iostream>
#include<string>
#include<vector>
#include"student.hpp"
using namespace std;

const int STUDENT_MAX=2;
const string INVALID_ID="Empty field";

Student::Student(string student_id,string name)
:Member(name,STUDENT_MAX)
{
    if(student_id=="")
    {
        cout<<INVALID_ID<<'\n';
        exit(EXIT_SUCCESS);
    }
    id=student_id;
}
