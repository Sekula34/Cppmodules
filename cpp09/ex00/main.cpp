#include <exception>
#include <iostream>
#include <stdexcept>


//return name of inputFile
//throw runtime error if number of arguments is different than 2 or fileName is empty
std::string getInputFileName(int argc, char** argv)
{
	std::string fileName;
	if (argc != 2)
		throw std::runtime_error("Program need only input file as agument");
	fileName = argv[1];
	if (fileName.empty())
		throw std::runtime_error("File name is empty");
	return (fileName);
}


int main(int argc, char** argv)
{
	try 
	{
		std::string inputFile;
		std::cout<<"Hello" << std::endl;
		inputFile = getInputFileName(argc, argv);
		std::cout <<"Input file name is :[" << inputFile <<"]"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}
