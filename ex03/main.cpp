#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void printSeparator(std::string const &title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void test1_BasicFunctionality()
{
    printSeparator("TEST 1: Basic Functionality (Subject Test)");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
}

void test2_FullInventory()
{
    printSeparator("TEST 2: Full Inventory (4 slots)");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    std::cout << "Equipping 4 materias..." << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    
    std::cout << "Trying to equip 5th materia (should be ignored)..." << std::endl;
    AMateria* extra = src->createMateria("ice");
    me->equip(extra);
    delete extra; // delete since it wasn't equipped
    
    ICharacter* target = new Character("target");
    std::cout << "\nUsing all 4 slots:" << std::endl;
    me->use(0, *target);
    me->use(1, *target);
    me->use(2, *target);
    me->use(3, *target);
    
    delete target;
    delete me;
    delete src;
}

void test3_InvalidSlots()
{
    printSeparator("TEST 3: Invalid Slot Usage");
    
    ICharacter* me = new Character("me");
    ICharacter* target = new Character("target");
    
    std::cout << "Using empty slots (should do nothing):" << std::endl;
    me->use(0, *target); // Empty slot
    me->use(1, *target); // Empty slot
    me->use(-1, *target); // Invalid index
    me->use(99, *target); // Invalid index
    
    delete target;
    delete me;
}

void test4_UnequipAndReuse()
{
    printSeparator("TEST 4: Unequip and Re-equip");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    ICharacter* target = new Character("target");
    
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    
    std::cout << "Equipping ice and cure..." << std::endl;
    me->equip(ice);
    me->equip(cure);
    
    std::cout << "\nUsing slot 0 (ice):" << std::endl;
    me->use(0, *target);
    
    std::cout << "\nUnequipping slot 0..." << std::endl;
    me->unequip(0);
    
    std::cout << "\nTrying to use slot 0 (should do nothing):" << std::endl;
    me->use(0, *target);
    
    std::cout << "\nRe-equipping ice to slot 0..." << std::endl;
    me->equip(ice);
    
    std::cout << "\nUsing slot 0 again:" << std::endl;
    me->use(0, *target);
    
    std::cout << "\nUnequipping for cleanup..." << std::endl;
    me->unequip(0);
    me->unequip(1);
    
    delete ice;
    delete cure;
    delete target;
    delete me;
    delete src;
}

void test5_UnknownMateriaType()
{
    printSeparator("TEST 5: Unknown Materia Type");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    
    std::cout << "Creating known materia 'ice'..." << std::endl;
    AMateria* ice = src->createMateria("ice");
    if (ice)
        std::cout << "✓ Created: " << ice->getType() << std::endl;
    
    std::cout << "\nCreating unknown materia 'fire'..." << std::endl;
    AMateria* fire = src->createMateria("fire");
    if (!fire)
        std::cout << "✓ Returned NULL (expected)" << std::endl;
    
    std::cout << "\nCreating unknown materia 'lightning'..." << std::endl;
    AMateria* lightning = src->createMateria("lightning");
    if (!lightning)
        std::cout << "✓ Returned NULL (expected)" << std::endl;
    
    delete ice;
    delete src;
}

void test6_MateriaSourceFull()
{
    printSeparator("TEST 6: MateriaSource Full (4 templates)");
    
    IMateriaSource* src = new MateriaSource();
    
    std::cout << "Learning 4 materias..." << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "Trying to learn 5th materia (should be ignored)..." << std::endl;
    AMateria* extra = new Ice();
    src->learnMateria(extra);
    delete extra; // Must delete since it wasn't learned
    
    std::cout << "\nCreating materias from learned templates:" << std::endl;
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    if (m1)
        std::cout << "✓ Created: " << m1->getType() << std::endl;
    if (m2)
        std::cout << "✓ Created: " << m2->getType() << std::endl;
    
    delete m1;
    delete m2;
    delete src;
}

int	main(void)
{
    test1_BasicFunctionality();
    test2_FullInventory();
    test3_InvalidSlots();
    test4_UnequipAndReuse();
    test5_UnknownMateriaType();
    test6_MateriaSourceFull();
    
    return (0);
}