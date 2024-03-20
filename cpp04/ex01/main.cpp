#include <iostream>
#include "Brain.hpp"
#include "WrongCat.hpp"

int main()
{
	Brain mozak;
	Brain mozak2;

	mozak2 = mozak;
	mozak2.listIdeas();
	return 0;
}
