#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();
    // delete meta;
    delete j;
    delete i;

    const int ARRAY_LEN = 10;
    AAnimal* animal_array[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; i++) {
        if (i % 2 == 0) {
            animal_array[i] = new Cat();
        } else {
            animal_array[i] = new Dog();
        }
    }
    for (int i = 0; i < ARRAY_LEN; i++) {
        std::cout << "---delete:" << i << "---" << std::endl;
        delete animal_array[i];
    }
    return 0;
}
