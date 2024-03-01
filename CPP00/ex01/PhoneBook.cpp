#include "PhoneBook.hpp"

//return true if input is valid (ADD, SEARCH, EXIT)
//return false and print message if it is empty or something else 
bool input_checker(std::string input)
{
	std::string valid[] = {"ADD", "SEARCH", "EXIT"};
	if (input.empty() == true)
	{
		return (false);
	}
	for (unsigned long i = 0; i<valid->size(); i++)
	{
		if(input == valid[i])
			return (true);
	}
	std::cerr << "Not valid input" << std::endl;
	return (false);
}

bool Contact::set_name(std::string &name, std::string name_msg)
{
	do
	{
		std::cout << "Enter your " << name_msg << ": "; 
		std::getline(std::cin, name);
		if (std::cin.fail() == true)
		{
			std::cerr << "Cin failed" << std::endl;
			return (false);
		}
	} while (name.empty() == true);
	return(true);
}

//return true if phone digit is plus minus paranthesis or space
//return false if it is not
bool Contact::check_phone_digit(char c)
{
	const char valid[] = {'+', '-', ' ', '(', ')'};

	for(unsigned long i = 0; i < 5; i++)
	{
		if (c == valid[i])
			return (true);
	}
	if(std::isdigit(c) != 0)
		return (true);
	return (false);
}

bool Contact::set_phone_number()
{
	do
	{
		std::cout <<"Enter your phone number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.fail() == true)
		{
			std::cerr << "Cin failed" << std::endl;
			return (false);
		}
	}while(check_phone_number() == false);
	return (true);
}

//return false if phone numebr is not number or + () space
//return true if ok
bool Contact::check_phone_number()
{
	if (phone_number.empty() == true)
	{
		std::cerr<< "Phone number is empty." << std::endl;
		return (false);
	}
	for (unsigned long i = 0; i < phone_number.size(); i++)
	{
		if(check_phone_digit(phone_number[i]) == false)
		{
			std::cerr<< "Invalid phone number" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool Contact::create_contact()
{
	if(set_name(this->first_name, "first name") == false)
		return (false);
	if(set_name(this->last_name, "last name") == false)
		return (false);
	if(set_name(this->nickname, "nickname") == false)
		return (false);
	if(set_phone_number() == false)
		return (false);
	if(set_name(this->darkest_secret, "darkest_secret") == false)
		return (false);
	return (true);
}

std::string Contact::truncate_string(std::string str)
{
	std::string truncated;

	if(str.length() > 10)
	{
		truncated = str.substr(0, 9);
		truncated.append(".");
	}
	else 
	{
		truncated = str;
	}
	return (truncated);
}

void Contact::print_contact(int index)
{
	std::cout << "|" << std::setw(10) << std::setfill(' ')<< index; 
	std::cout << "|" << std::setw(10) << std::setfill(' ')<< truncate_string(first_name);
	std::cout << "|" << std::setw(10) << std::setfill(' ')<< truncate_string(last_name); 
	std::cout << "|" << std::setw(10) << std::setfill(' ')<< truncate_string(nickname) << "|" << std::endl;
	std::cout << std::setw(45) << std::setfill('-') << "-" <<std::endl;
}

void PhoneBook::add(Contact contact_name)
{
	book[index] = contact_name;
	index ++;
	if(number_of_contacts < 8)
		number_of_contacts ++;
	if(index > 7)
		index = 0;
}

void PhoneBook::print_header()
{
	std::cout << std::setw(45) << std::setfill('-') << "-" <<std::endl;
	std::cout << std::setfill(' ');
	std::cout << "|" <<std::setw(10); std::cout << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|"; 
	std::cout << std::setw(10) << "last name" << "|";
 	std::cout << std::setw(10) << "nickname" << "|" <<std::endl;
	std::cout << std::setw(45) << std::setfill('-') << "-" <<std::endl;
	// std::cout << "|index|first name|last name|nickname|" <<std::endl;
	// std::cout << "-------------------------------------" <<std::endl;
}
void PhoneBook::search()
{
	print_header();
	for(int i = 0; i < number_of_contacts; i++)
	{
		book[i].print_contact(i);
	}
}

bool get_input(std::string& input)
{
	std::string prompt_message ("Enter one of the following: \n\tADD\n\tSEARCH \n\tEXIT \nInput: ");
	std::cout << prompt_message;
	std::getline(std::cin, input);
	if(std::cin.fail() == true)
	{
		std::cerr << "Cin failed" << std::endl;
		return (false);
	}
	return (true);
}

int main()
{
	std::string first_message ("Program started!\nPhone book is empty");
	std::string input;
	PhoneBook my_contacts;
	my_contacts.index = 0;
	my_contacts.number_of_contacts = 0;
	std::cout << first_message << std::endl; 
	while(1)
	{
		Contact filip;
		if(get_input(input) == false)
			return 1;
		if (input_checker(input) == false)
		{
			input.erase();
			continue;
		}
		if(input == "ADD")
		{
			filip.create_contact();
			my_contacts.add(filip);
			//my_contacts.add();

		}
		if(input == "SEARCH")
		{
			my_contacts.search();

		}

	}

	return (0);

}
