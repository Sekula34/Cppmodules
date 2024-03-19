#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(const WrongCat& source);
		WrongCat& operator=(const WrongCat& source);
		~WrongCat();
		void makeSound(void) const;
};

#endif
