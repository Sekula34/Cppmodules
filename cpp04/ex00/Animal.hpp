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
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType(void) const;
};

#endif
