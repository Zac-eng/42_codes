#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal {

protected:
    std::string type;

public:
    AAnimal(void);
    AAnimal(const AAnimal& object);
    virtual ~AAnimal();
    AAnimal& operator = (const AAnimal& object);
    std::string getType(void) const;
    virtual void makeSound(void) const = 0;

};

#endif
