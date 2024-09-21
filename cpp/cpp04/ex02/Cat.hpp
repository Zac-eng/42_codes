#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal {

private:
    Brain* brain;

public:
    Cat(void);
    Cat(const Cat& object);
    ~Cat();
    Cat& operator = (const Cat& object);
    void makeSound(void) const;

};

#endif
