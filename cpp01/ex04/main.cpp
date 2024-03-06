#include <exception>
#include <iostream>
#include <fstream>
#include "FileReplacer.hpp"


int main()
{
	std::string line;
	FileReplacer myFile("filename", "re", "nemoj");
	
	if(myFile.createNewFile() != true)
		return (1);
	std::cout << "done " << std::endl;
	return (0);
}
