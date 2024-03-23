#ifndef CURE_HPP
# define CURE_HPP
# include "../AMateria.hpp"
# include "../Character/ICharacter.hpp"

class Cure : public AMateria
{
	public:
	//orthodox
		Cure(void);
		Cure(Cure& source);
		Cure& operator=(Cure& source);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
