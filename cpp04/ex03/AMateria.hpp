#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria 
{
	protected: 
		//[...]
	public:
	//orthodox
		AMateria(void);
		AMateria(const AMateria& source);
		AMateria& operator=(const AMateria& source);
		~AMateria();

		AMateria(std::string const& type);
		//[...]
		
		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
