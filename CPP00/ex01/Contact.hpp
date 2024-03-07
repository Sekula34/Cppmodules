#ifndef CONTACT_HPP
# define CONTACT_HPP
#include<string>
#include<iostream>
#include<cctype>
#include<iomanip>
#include<sstream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		bool check_phone_digit(char c);
		bool check_phone_number();
		bool set_name(std::string &name, std::string name_msg);
		bool set_phone_number();
		std::string truncate_string(std::string);
	public :
		bool create_contact(void);
		void print_contact(int index);
		void print_full_contact(void);
};

#endif
