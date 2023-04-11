#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete j;
        delete i;
        delete meta;
    }

    std::cout << BLUE "\nStack allocation to respective classes" RES << std::endl;
    {
        Animal const animal;
        Dog const dog;
        Cat const cat;

        std::cout << dog.getType() << " " << std::endl;
        std::cout << cat.getType() << " " << std::endl;
        std::cout << animal.getType() << " " << std::endl;

        dog.makeSound();
        cat.makeSound();
        animal.makeSound();
    }

    std::cout << BLUE "\nStack allocation to Animal class only" RES << std::endl;
    {
        Animal const animal = Animal();
        Animal const dog = Dog();
        Animal const cat = Cat();

        std::cout << dog.getType() << " " << std::endl;
        std::cout << cat.getType() << " " << std::endl;
        std::cout << animal.getType() << " " << std::endl;

        dog.makeSound();
        cat.makeSound();
        animal.makeSound();
    }

    std::cout << BLUE "\nWrongAnimal/WrongCat Heap allocation (virtual diff)" RES << std::endl;
    {
        const WrongAnimal* animal = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();

        std::cout << cat->getType() << " " << std::endl;
        std::cout << animal->getType() << " " << std::endl;

        cat->makeSound();
        animal->makeSound();

        delete cat;
        delete animal;
    }

    std::cout << BLUE "\nWrongAnimal/WrongCat Stack allocation to respective classes" RES << std::endl;
    {
        WrongAnimal const animal;
        WrongCat const cat;

        std::cout << cat.getType() << " " << std::endl;
        std::cout << animal.getType() << " " << std::endl;

        cat.makeSound();
        animal.makeSound();
    }

    std::cout << BLUE "\nWrongAnimal/WrongCat Stack allocation to WrongAnimal class" RES << std::endl;
    {
        WrongAnimal const animal = WrongAnimal();
        WrongAnimal const cat = WrongCat();

        std::cout << cat.getType() << " " << std::endl;
        std::cout << animal.getType() << " " << std::endl;

        cat.makeSound();
        animal.makeSound();
    }

    return 0;
}
