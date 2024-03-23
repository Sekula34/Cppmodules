#include "Contact.hpp"
#include<iostream>
#include<cctype>
#include<iomanip>


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

void Contact::print_full_contact(void)
{
	std::cout << std::setfill(' ');
	std::cout << std::setw(20) <<"First Name: " << first_name << std::endl;
	std::cout << std::setw(20) <<"Last Name: " << last_name << std::endl;
	std::cout << std::setw(20) <<"Nickname: " << nickname << std::endl;
	std::cout << std::setw(20) <<"Phone number: " << phone_number << std::endl;
	std::cout << std::setw(20) <<"Darkest secret: " << darkest_secret << std::endl;
}
