#ifndef Dog_HPP
# define Dog_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal {

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
