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

bool get_input(std::string& input)
{
	std::string prompt_message ("Enter one of the following: \n\tADD\n\tSEARCH \n\tEXIT");
	std::cout << prompt_message << std::endl;
	std::getline(std::cin, input);
	if(std::cin.fail() == true)
	{
		std::cerr << "Cin failed" << std::endl;
		return false;
	}
	return true ;
}

int main()
{
	std::string first_message ("Program started!\nPhone book is empty");
	std::string input;
	PhoneBook my_contacts;

	std::cout<< first_message << std::endl; 
	while(1)
	{
		if(get_input(input) == false)
			return 1;
		if (input_checker(input) == false)
		{
			input.erase();
			continue;
		}
		if(input == "ADD")
		{
			//my_contacts.add();

		}
		if(input == "SEARCH")
		{
			//my_contacts.search

		}

	}
	return (0);

}
