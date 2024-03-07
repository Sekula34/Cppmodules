#include <exception>
#include <iostream>
#include <fstream>
#include "FileReplacer.hpp"


int main(int argc, char **argv)
{

	if(argc != 4)
	{
		std::cerr << "Program takes three parameters in the following order: ";
		std::cerr << "a filename and two strings s1 and s2" << std::endl;
		return (1);
	}
	std::string fileName(argv[1]);
	std::string oldString(argv[2]);
	std::string newString(argv[3]);
	FileReplacer myFile(fileName, oldString, newString);
	if(myFile.createNewFile() != true)
		return (1);
	std::cout << "done " << std::endl;
	return (0);
}
