#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include <vector>
#include <string>
#include "professor.hpp"
#include "student.hpp"
#include "book.hpp"
#include "magazine.hpp"
#include "reference.hpp"

class Library {
public:
	void add_student_member(std::string student_id, std::string student_name);
	void add_prof_member(std::string prof_name);
	void add_book(std::string book_title, int copies);
	void add_magazine(std::string magazine_title, int year, int number, int copies);
	void add_reference(std::string reference_title, int copies);
	void borrow(std::string member_name, std::string document_title);
	void extend(std::string member_name, std::string document_title);
	void return_document(std::string member_name, std::string document_title);
	int get_total_penalty(std::string member_name);
	void numbers_check(int year,int number);
	std::vector<std::string> available_titles();
	void time_pass(int days);
	bool unique_member(std::string new_name);
	bool unique_document(std::string new_name);
	int find_member(std::string member_name);
private:
    std::vector<Member*> members;
    std::vector<Document*> documents;
    int current_day=1;
};

#endif