#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	_type = weaponType;
}

const std::string& Weapon::getType() const
{
	const std::string& typeRef = _type;
	return (typeRef);
}

void Weapon::setType(std::string newWeaponType)
{
	_type = newWeaponType;
}
