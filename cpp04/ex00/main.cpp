#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "WrongCat.hpp"


void subjectTest(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i; 
    delete j;
}


void subjectTestWrong(void)
{
    WrongCat krivamacka;

    krivamacka.makeSound();
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* j = new WrongCat();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i; 
    delete j;
}


int main()
{
    subjectTestWrong();
    subjectTest();
    return 0;
}
