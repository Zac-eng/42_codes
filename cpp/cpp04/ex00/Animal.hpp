#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {

protected:
    std::string type;

public:
    Animal(void);
    Animal(const Animal& object);
    virtual ~Animal();
    Animal& operator = (const Animal& object);
    std::string getType(void) const;
    virtual void makeSound(void) const;

};

#endif
