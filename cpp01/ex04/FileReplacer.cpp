#include "FileReplacer.hpp"

#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(std::string FileName,std::string oldString, std::string newString) : _fileName(FileName), _stringToReplace(oldString), _newString(newString)
{
	if(_stringToReplace.empty() == true)
		throw std::runtime_error("string to replace cannot be empty");
		
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
	while(std::getline(firstFile, oneLine))
	{
		std::cout << oneLine << std::endl;
	}
	firstFile.close();
}

bool FileReplacer::createNewFile()
{
	std::string originalLine;
	std::fstream originalFile(_fileName.c_str(), std::fstream::in);
	std::string newFileName(_fileName + ".replace");
	if(originalFile.is_open() == false)
	{
		std::cerr << "Cannot open file \"" << _fileName << "\"" << std::endl;
		return false;
	}
	std::fstream fileReplace(newFileName.c_str(), std::fstream::out | std::fstream::trunc);
	if (fileReplace.is_open() == false)
	{
		originalFile.close();
		std::cerr << "Cannot open/create file \"" << newFileName << "\"" << std::endl;
		return false;
	}
	std::string fullFileString;
	char ch;
	while(originalFile.get(ch))
	{
		fullFileString += ch;
	}
	fileReplace << _updatedLine(fullFileString);
	originalFile.close();
	fileReplace.close();
	return true;
}

std::string FileReplacer::_updatedLine(std::string oldLine)
{
	std::string updatedLine(oldLine);
	size_t position;

	position = updatedLine.find(_stringToReplace);
	if(position == std::string::npos)
		return(updatedLine);
	while(position != std::string::npos)
	{
		updatedLine.erase(position, _stringToReplace.size());
		updatedLine.insert(position, _newString);
		position = updatedLine.find(_stringToReplace, position + _newString.size());
	}
	return (updatedLine);

}
