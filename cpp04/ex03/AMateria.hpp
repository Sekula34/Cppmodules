#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class ICharacter;

class AMateria 
{
	protected:
		std::string m_type;
		//[...]
	public:
	//orthodox
		AMateria(void);
		AMateria(const AMateria& source);
		AMateria& operator=(const AMateria& source);
		virtual ~AMateria();

		AMateria(std::string const& type);
		//[...]
		
		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
