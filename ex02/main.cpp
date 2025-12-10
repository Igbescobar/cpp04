#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// Test 1: Cannot instantiate abstract class
	// AAnimal animal;  // ERROR: cannot instantiate abstract class

	std::cout << "=== Test 1: Basic polymorphism ===" << std::endl;
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;
	std::cout << std::endl;

	// Test 2: Array of Animals (half Dog, half Cat)
	std::cout << "=== Test 2: Array of Animals ===" << std::endl;
	AAnimal *animals[4];

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int idx = 0; idx < 4; idx++)
		delete animals[idx];
	std::cout << std::endl;

	// Test 3: Deep copy test
	std::cout << "=== Test 3: Deep copy ===" << std::endl;
	Dog dog1;
	Dog dog2 = dog1;

	Cat cat1;
	Cat cat2 = cat1;
	std::cout << std::endl;

	// Test 4: Assignment operator
	std::cout << "=== Test 4: Assignment operator ===" << std::endl;
	Dog dogA;
	Dog dogB;
	dogA = dogB;

	return (0);
}