#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "WrongAnimal.hpp"
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

void wrongAnimal(void)
{
    WrongCat mica;
    mica.makeSound();
}


//some of my testes
//this one proves that animal* can point to dog*
void test3(void)
{
    Dog *dogptr;

    dogptr = new Dog();
    dogptr->makeSound();
    std::cout << dogptr->getType() << " hello" << std::endl;
    Animal* animalPtr;

    animalPtr = dogptr;

    std::cout << "Printing with animal Ptr" << std::endl;
    animalPtr->makeSound();
    delete dogptr;
}

//this one proves that animal* can point to cat* and freeing can be done with animal*
void test4(void)
{
    Cat *dogptr;

    dogptr = new Cat();
    dogptr->makeSound();
    std::cout << dogptr->getType() << " hello" << std::endl;
    Animal* animalPtr;

    animalPtr = dogptr;

    std::cout << "Printing with animal Ptr" << std::endl;
    animalPtr->makeSound();
    delete animalPtr;
}

//use and instantiate the class
void test5()
{
    Animal my_animal;

    my_animal.makeSound();
}

int main()
{
    wrongAnimal();
    subjectTestWrong();
    subjectTest();

    test3();
    test4();
    test5();
    return 0;
}
