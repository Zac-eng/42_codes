#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {

private:
    Brain* brain;

public:
    Dog(void);
    Dog(const Dog& object);
    ~Dog();
    Dog& operator = (const Dog& object);
    void makeSound(void) const;

};

#endif
