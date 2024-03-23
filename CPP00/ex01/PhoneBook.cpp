#include "PhoneBook.hpp"
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>


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

bool PhoneBook::valid_index(int& index)
{
	std::string index_str;
	std::cout << "Enter the index of entry to display: ";
	std::getline(std::cin, index_str);
	if(std::cin.fail() == true)
		return (false);
	std::istringstream integer_stream(index_str);
	if (!(integer_stream >> index))
	{
		std::cerr << "Invalid input" << std::endl;
		return (false);
	}
	if(number_of_contacts == 0)
	{
		std::cerr << "There are no contacts in book at all" << std::endl;
		return (false);
	}
	if(index < 0 || index >= number_of_contacts)
	{
		std::cerr << "Index is out of range or wrong"<< std::endl;
		return (false);
	}
	return(true);

}
void PhoneBook::search()
{
	int index(-1);
	print_header();
	for(int i = 0; i < number_of_contacts; i++)
	{
		book[i].print_contact(i);
	}
	if(valid_index(index) == false)
		return ;
	book[index].print_full_contact();
}



