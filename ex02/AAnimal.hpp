#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
  public:
	AAnimal();
	AAnimal(AAnimal const &src);
	virtual ~AAnimal();

	AAnimal &operator=(AAnimal const &rhs);
	void setType(std::string const &type);

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;

  private:
  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &o, AAnimal const &i);

#endif /* ********************************************************** ANIMAL_H */