#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal 
{
    protected:
        std::string type;

    public :
        Animal(void);
        Animal(const Animal& source);
        Animal& operator=(const Animal& source);
        ~Animal();
        void makeSound();
};

#endif
