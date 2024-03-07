#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include<string>
#include<iostream>
#include<cctype>
#include<iomanip>
#include<sstream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact book[8];
		void print_header(void);
		bool valid_index(int &index);
	public:
		int number_of_contacts;
		int index;
		void add(Contact new_contact);
		void search(void);
};


#endif
