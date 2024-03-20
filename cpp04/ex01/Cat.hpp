#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal 
{
	private :
		Brain *brainPtr;
	public :
		Cat(void);
		Cat(const Cat& source);
		Cat& operator=(const Cat& source);
		~Cat();

		void makeSound(void) const;
};

#endif
