#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <string>

class AMateria;

class ICharacter 
{
	public :
		//orthodox 
		ICharacter(void);
		ICharacter(ICharacter &source);
		ICharacter& operator=(ICharacter &source);
		virtual ~ICharacter() {};

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void uneqip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

};

#endif
