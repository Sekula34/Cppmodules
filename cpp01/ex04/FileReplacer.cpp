#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string FileName,std::string oldString, std::string newString) : _fileName(FileName), _stringToReplace(oldString), _newString(newString)
{
}

void FileReplacer::printFileContent()
{
	std::string oneLine;
	std::fstream firstFile(_fileName.c_str(), std::fstream::in);
	if(firstFile.is_open() == false)
	{
		std::cerr << "Cannot open file " << _fileName.c_str() << std::endl;
		return ;
	}
	std::cout << "Content of file \"" <<_fileName.c_str() << "\" is: "<< std::endl;
	while(getline(firstFile, oneLine))
	{
		std::cout << oneLine << std::endl;
	}
	firstFile.close();
}

bool FileReplacer::createNewFile()
{
	std::string newFileName(_fileName + ".replace");
	std::fstream fileReplace(newFileName.c_str(), std::fstream::out | std::fstream::trunc);
	if (fileReplace.is_open() == false)
	{
		std::cerr << "Cannot open/create file \"" << newFileName << "\"" << std::endl;
		return false;
	}
	return true;
}

std::string FileReplacer::_updatedLine(std::string oldLine)
{
	std::string updatedLine(oldLine);
	size_t position;

	std::cout << "old line is "<< oldLine << std::endl;
	std::cout << "string to replace is " << _stringToReplace << std::endl;
	std::cout << "new string is " << _newString << std::endl;
	position = updatedLine.find(_stringToReplace);
	if(position == std::string::npos)
		return(updatedLine);
	updatedLine.erase(position, _stringToReplace.size());
	updatedLine.insert(position, _newString);
	return (updatedLine);

}
