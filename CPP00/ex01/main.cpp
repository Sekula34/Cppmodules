#include "PhoneBook.hpp"


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
			continue;
		if(input == "ADD")
		{
			filip.create_contact();
			my_contacts.add(filip);
		}
		if(input == "SEARCH")
			my_contacts.search();
		if(input == "EXIT")
			break;
		std::cout << std::endl;
	}
	return (0);
}
