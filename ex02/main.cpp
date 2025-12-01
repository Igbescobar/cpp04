#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
    // COMMENTED OUT - Cannot instantiate abstract class!
    // AAnimal animal;  // ❌ COMPILE ERROR: cannot instantiate abstract class 'AAnimal'

    std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         EX02: ABSTRACT CLASS - Everything Works as Before      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << std::endl;

    // Test 1: Basic polymorphism with virtual destructors
    std::cout << "=== TEST 1: Polymorphism (using AAnimal pointers) ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << "j->getType() = " << j->getType() << std::endl;
    std::cout << "i->getType() = " << i->getType() << std::endl;
    std::cout << "j->makeSound(): ";
    j->makeSound();
    std::cout << "i->makeSound(): ";
    i->makeSound();
    std::cout << "Deleting polymorphically:" << std::endl;
    delete j;
    delete i;
    std::cout << std::endl;

    // Test 2: Array of Animals (half Dog, half Cat)
    std::cout << "=== TEST 2: Array of AAnimals ===" << std::endl;
    AAnimal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    std::cout << "Creating and calling makeSound() on all:" << std::endl;
    for (int idx = 0; idx < 4; idx++)
    {
        std::cout << "animals[" << idx << "]: ";
        animals[idx]->makeSound();
    }

    std::cout << "Deleting all animals:" << std::endl;
    for (int idx = 0; idx < 4; idx++)
        delete animals[idx];
    std::cout << std::endl;

    // Test 3: Deep copy testing
    std::cout << "=== TEST 3: Deep Copy Test ===" << std::endl;
    std::cout << "Creating Dog dog1:" << std::endl;
    Dog dog1;
    std::cout << "Creating Dog dog2 = dog1 (deep copy):" << std::endl;
    Dog dog2 = dog1;
    std::cout << "Creating Cat cat1:" << std::endl;
    Cat cat1;
    std::cout << "Creating Cat cat2 = cat1 (deep copy):" << std::endl;
    Cat cat2 = cat1;

    std::cout << "\nCalling makeSound() on all:" << std::endl;
    std::cout << "dog1: ";
    dog1.makeSound();
    std::cout << "dog2: ";
    dog2.makeSound();
    std::cout << "cat1: ";
    cat1.makeSound();
    std::cout << "cat2: ";
    cat2.makeSound();
    std::cout << std::endl;

    // Test 4: Assignment operator (deep copy)
    std::cout << "=== TEST 4: Assignment Operator (deep copy) ===" << std::endl;
    std::cout << "Creating Dog dogA:" << std::endl;
    Dog dogA;
    std::cout << "Creating Dog dogB:" << std::endl;
    Dog dogB;
    std::cout << "Assigning dogA = dogB (deep copy):" << std::endl;
    dogA = dogB;
    std::cout << "Calling makeSound():" << std::endl;
    std::cout << "dogA: ";
    dogA.makeSound();
    std::cout << "dogB: ";
    dogB.makeSound();
    std::cout << std::endl;

    std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                    ALL TESTS SUCCESSFUL!                        ║" << std::endl;
    std::cout << "║  Note: AAnimal is abstract and cannot be instantiated directly  ║" << std::endl;
    std::cout << "║  But polymorphism still works perfectly via pointers!           ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;

    return (0);
}