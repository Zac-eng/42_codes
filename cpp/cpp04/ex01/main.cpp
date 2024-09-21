#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        std::cout << "---basic test---" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
        std::cout << std::endl;
    }
    {
        std::cout << "---deep copy test---" << std::endl;
        const Cat* a = new Cat();
        const Cat copy = *a;
        delete a;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    const int ARRAY_LEN = 10;
    Animal* animal_array[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; i++) {
        std::cout << "---create:" << i << "---" << std::endl;
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
