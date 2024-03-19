#include "Animal.hpp"

int main()
{
    Animal first;
    Animal second(first);
    Animal third;
    third = first;

    first.makeSound();
    return (0);
}
