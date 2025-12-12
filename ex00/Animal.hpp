#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
  public:
	Animal();
	Animal(Animal const &src);
	virtual ~Animal();

	Animal &operator=(Animal const &rhs);
	void setType(std::string const &type);

	std::string getType(void) const;
	virtual void makeSound(void) const;

  private:
  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &o, Animal const &i);

#endif /* ********************************************************** ANIMAL_H */