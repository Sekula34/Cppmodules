#ifndef ICE_HPP
# define ICE_HPP
# include "../AMateria.hpp"
# include "../Character/ICharacter.hpp"

class Ice : public AMateria
{
	public:
		//orthodox
		Ice(void);
		Ice(Ice& source);
		Ice& operator=(Ice& source);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
