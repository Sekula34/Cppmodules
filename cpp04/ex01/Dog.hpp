#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain* brainPtr;
	public :
		Dog(void);
		Dog(const Dog& source);
		Dog& operator= (const Dog& source);
		~Dog(void);
		void makeSound(void) const;


		void setIdea(std::string, int index);
		void tellEverything() const;
};

#endif
