#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::srand(time(NULL));

    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }

    std::cout << BLUE "\nCreate multiple instances of Animal and destroy then" RES << std::endl;
    {
        int const numAnimals = 6;
        Animal *animals[numAnimals];

        int i = 0;
        for (; i < numAnimals / 2; i++) {
            animals[i] = new Cat();
        }
        for (; i < numAnimals; i++) {
            animals[i] = new Dog();
        }

        for (i = 0; i < numAnimals; i++) {
            delete animals[i];
        }
    }

    std::cout << BLUE "\nCat and Dog deep copies test" RES << std::endl;
    {
        Cat cat;
        const Animal* copyCat1 = new Cat(cat);
        const Cat*    copyCat2 = new Cat(cat);

        std::cout << "     cat(" YELLOW << &cat << RES ")" << std::endl;
        std::cout << "copyCat1(" YELLOW << copyCat1 << RES ")" << std::endl;
        std::cout << "copyCat2(" YELLOW << copyCat2 << RES ")" << std::endl;
        delete copyCat1;
        delete copyCat2;


        Dog dog;
        Dog copyDog = dog;

        std::cout << "    dog(" YELLOW << &dog << RES ")" << std::endl;
        std::cout << "copyDog(" YELLOW << &copyDog << RES ")" << std::endl;
    }

    std::cout << BLUE "\nBrain deep copies test" RES << std::endl;
    {
        Cat cat;
        Brain *catBrain = cat.getBrain();

        const Cat* copyCat = new Cat(cat);
        Brain *copyCatBrain = copyCat->getBrain();


        std::cout << "    catBrain(" YELLOW << catBrain << RES ")" << std::endl;
        std::cout << "copyCatBrain(" YELLOW << copyCatBrain << RES ")" << std::endl;
        delete copyCat;
    }

    std::cout << BLUE "\nCat brain ideas" RES << std::endl;
    {
        Cat foo;
        Cat bar;

        Brain *fooBrain = foo.getBrain();
        Brain *barBrain = bar.getBrain();

        std::cout << ORANGE "Cat" BLUE " foo " RES "idea: " GREEN << fooBrain->getIdea(0) << RES << std::endl;
        std::cout << ORANGE "Cat" BLUE " bar " RES "idea: " GREEN << barBrain->getIdea(0) << RES << std::endl;
    }

    std::cout << BLUE "\nDog brain ideas" RES << std::endl;
    {
        Dog foo;
        Dog bar;

        Brain *fooBrain = foo.getBrain();
        Brain *barBrain = bar.getBrain();

        std::cout << ORED "Dog" BLUE " foo " RES "idea: " GREEN << fooBrain->getIdea(0) << RES << std::endl;
        std::cout << ORED "Dog" BLUE " bar " RES "idea: " GREEN << barBrain->getIdea(0) << RES << std::endl;
    }

    return 0;
}
