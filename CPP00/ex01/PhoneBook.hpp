#ifndef PHONEBOOK
# define PHONEBOOK
#include<string>
#include<iostream>
#include<cctype>

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
	public :
		bool create_contact(void);
};

class PhoneBook
{
	private:
		Contact book[8];
		static int index;
	public:
		void add(Contact new_contact);
		void search(void);
};


#endif
