#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "=== POLYMORPHISM TEST ===" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Creating Animal, Dog, and Cat ---" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl;

	std::cout << "--- Testing getType() ---" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing makeSound() (polymorphic) ---" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "--- Creating WrongAnimal and WrongCat ---" << std::endl;
	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_i = new WrongCat();
	std::cout << std::endl;

	std::cout << "--- Testing getType() ---" << std::endl;
	std::cout << wrong_i->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing makeSound() (NOT polymorphic) ---" << std::endl;
	std::cout << "Notice: WrongCat will use WrongAnimal's makeSound because it's not virtual!" << std::endl;
	wrong_i->makeSound();
	// will output the wrong animal sound because makeSound is not virtual!
	wrong_meta->makeSound();
	std::cout << std::endl;

	return (0);
}