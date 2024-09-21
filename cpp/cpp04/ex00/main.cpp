#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
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
    delete j;
    delete i;

    std::cout << "---case for non-virtual function overridden---" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    std::cout << wrong->getType() << " " << std::endl;
    wrong->makeSound();
    delete wrong;
    return 0;
}
