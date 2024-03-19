#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal 
{
	protected :
		std::string wrongType;
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& source);
		WrongAnimal& operator=(const WrongAnimal &source);
		~WrongAnimal();

		void makeSound(void) const;
		std::string getType(void) const;
};


#endif
