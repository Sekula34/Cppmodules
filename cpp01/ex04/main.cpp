#include <exception>
#include <iostream>
#include <fstream>
#include "FileReplacer.hpp"

// bool checkInput(int argc, char **argv)
// {
// 	if(argc != 4)
// 	{
// 		std::cerr << "Program should take 3 arguments" << std::endl;
// 		return (false);
// 	}
// 	return (true);
// }

int main()
{
	std::string line;
	std::fstream file("primjertidajem",std::ios::in);
	FileReplacer myFile("primjertidajem", "makniiii", "0");
	
	myFile.printFileContent();
	myFile.createNewFile();
	std::cout << "done " << std::endl;
	std::cout << myFile._updatedLine("hmakniiii123") << std::endl;
	return (0);
}
