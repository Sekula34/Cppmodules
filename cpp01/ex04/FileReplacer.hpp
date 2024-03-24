#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

#include <string>

class FileReplacer
{
	private :
		std::string _fileName;
		std::string _stringToReplace;
		std::string _newString;
		std::string _updatedLine(std::string line);
	public :
		FileReplacer(std::string fileName, std::string oldString, std::string newString);
		void printFileContent();
		bool createNewFile();
};

#endif
