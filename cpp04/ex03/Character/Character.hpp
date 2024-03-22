#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
	private :
		AMateria* _materials[4];
		std::string _name;

	public :
	//orthdox
		Character(void);
		Character(Character& source);
		Character& operator=(Character& source);
		~Character();

		Character(std::string name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
