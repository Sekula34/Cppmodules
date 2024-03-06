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
	std::fstream fileReplace(newFileName.c_str(), std::fstream::out | std::fstream::trunc);
	if(originalFile.is_open() == false)
	{
		std::cerr << "Cannot open/create file \"" << _fileName << "\"" << std::endl;
		return false;
	}
	if (fileReplace.is_open() == false)
	{
		std::cerr << "Cannot open/create file \"" << newFileName << "\"" << std::endl;
		return false;
	}
	while(std::getline(originalFile, originalLine,'\0'))
	{
		//std::cout << "original line is " << _updatedLine(originalLine) << std::endl;
		fileReplace << _updatedLine(originalLine);

	}
	originalFile.close();
	fileReplace.close();
	return true;
}

std::string FileReplacer::_updatedLine(std::string oldLine)
{
	std::string updatedLine(oldLine);
	size_t position;

	// std::cout << "old line is "<< oldLine << std::endl;
	// std::cout << "string to replace is " << _stringToReplace << std::endl;
	// std::cout << "new string is " << _newString << std::endl;
	position = updatedLine.find(_stringToReplace);
	if(position == std::string::npos)
		return(updatedLine);
	while(position != std::string::npos)
	{
		updatedLine.erase(position, _stringToReplace.size());
		updatedLine.insert(position, _newString);
		position = updatedLine.find(_stringToReplace);
	}
	return (updatedLine);

}
