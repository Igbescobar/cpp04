#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);
	~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &rhs);
	void setType(std::string const &type);

	std::string getType(void) const;
	void makeSound(void) const;

  private:
  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i);

#endif
	/* ******************************************************* WRONGANIMAL_H */