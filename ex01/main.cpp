#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// Test 1: Basic polymorphism with virtual destructors
	std::cout << "=== TEST 1: Basic Polymorphism ===" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;
	std::cout << std::endl;

	// Test 2: Array of Animals (half Dog, half Cat)
	std::cout << "=== TEST 2: Array of Animals ===" << std::endl;
	Animal *animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int idx = 0; idx < 4; idx++)
		animals[idx]->makeSound();

	for (int idx = 0; idx < 4; idx++)
		delete animals[idx];
	std::cout << std::endl;

	// Test 3: Deep copy testing
	std::cout << "=== TEST 3: Deep Copy Test ===" << std::endl;
	Dog dog1;
	Dog dog2 = dog1; // Deep copy
	Cat cat1;
	Cat cat2 = cat1; // Deep copy

	dog1.makeSound();
	dog2.makeSound();
	cat1.makeSound();
	cat2.makeSound();
	std::cout << std::endl;

	// Test 4: Assignment operator (deep copy)
	std::cout << "=== TEST 4: Assignment Operator ===" << std::endl;
	Dog dogA;
	Dog dogB;
	dogA = dogB; // Deep copy assignment
	dogA.makeSound();
	dogB.makeSound();

	return (0);
}