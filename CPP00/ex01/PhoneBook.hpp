#ifndef PHONEBOOK
# define PHONEBOOK
#include<string>
#include<iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		bool set_name(std::string &name, std::string name_msg);
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
