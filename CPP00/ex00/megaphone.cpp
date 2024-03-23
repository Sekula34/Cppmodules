#include <iostream>
#include <string>

class Megaphone
{
	public :
		void yell(std::string sentence);
};

void Megaphone::yell(std::string sentence)
{
	char letter;
	std::string yelling;
	
	for(unsigned long i = 0; i < sentence.length(); i++)
	{
		letter = std::toupper(sentence[i]);
		yelling.append(1, letter);
	}
	std::cout << yelling;
}
int main(int argc, char **argv)
{
	Megaphone my_megaphone;
	std::string input;
	
	if(argc == 1)
		my_megaphone.yell(input);
	else
	{
		for (int i = 1; i < argc ; i++)
			my_megaphone.yell(argv[i]);
	}
	std::cout << std::endl;
	return(0);
}
