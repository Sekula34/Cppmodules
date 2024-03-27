#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include <dirent.h>


void ShrubberyCreationForm::_printactualTree(std::ofstream& _shrubberyFile) const
{
    _shrubberyFile << "      *       " << "      *       " << "      *       " << "      *       " << "      *       " << std::endl;
    _shrubberyFile << "     ***      " << "     ***      " << "     ***      " << "     ***      " << "     ***      " << std::endl;
    _shrubberyFile << "    *****     " << "    *****     " << "    *****     " << "    *****     " << "    *****     " << std::endl;
    _shrubberyFile << "   *******    " << "   *******    " << "   *******    " << "   *******    " << "   *******    " << std::endl;
    _shrubberyFile << "  *********   " << "  *********   " << "  *********   " << "  *********   " << "  *********   " << std::endl;
    _shrubberyFile << "     |||      " << "     |||      " << "     |||      " << "     |||      " << "     |||      " << std::endl;
}

void ShrubberyCreationForm::_printingFolders(struct dirent* file, std::ofstream& _shrubberyFile) const
{
	if(file->d_name[0] == '.')
		return;
	if(file->d_type == DT_DIR && file->d_name[0] != '.')
	{
		_shrubberyFile << "├─ ";
		_shrubberyFile << file->d_name << "/";
		_shrubberyFile << std::endl;
	}
}

void ShrubberyCreationForm::_printingFiles(std::ofstream& _shrubberyFile) const
{
	DIR* dir;
	struct dirent* file; 

	dir = opendir(".");
	if(dir == NULL)
	{
		throw std::runtime_error("Cannot open curent director");
	}
	_shrubberyFile << "ex02/" << std::endl;
	file = readdir(dir);
	while(file != NULL)
	{
		if(file->d_type == DT_DIR)
		{
			_printingFolders(file, _shrubberyFile);
		}
		if(file->d_type == DT_REG)
		{
			_shrubberyFile << "├─ ";
			_shrubberyFile << file->d_name << std::endl;
		}
		file = readdir(dir);
	}
	closedir(dir);
}

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("Shrubbery Creation Form", 145, 137)
{
	_target = "<Default Shrubbery Creation>"; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source)
:AForm(source.getName(), source.getGradeToSign(), source.getGradeToExecute())
{
	_target = source._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	this->_target = source._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137)
{
	if(target.empty() == true)
		throw std::runtime_error("Form name cannot be empty");
	_target = target;
}


// • ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(this->getIsSgined() == false)
		throw AForm::FormNotSignedException();
	this->requiredGradeCheck(executor.getGrade(), this->getGradeToExecute());
	std::cout << "Execution can start" << std::endl;
	std::ofstream _shrubberyFile;
	const std::string fileName(_target + "_shrubbery");
	_shrubberyFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	if(_shrubberyFile.fail() == true)
		throw std::runtime_error("Openig file failed");
	_printingFiles(_shrubberyFile);
	_printactualTree(_shrubberyFile);
}
