#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public AAnimal
{
  public:
	Cat();
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &rhs);
	void makeSound(void) const;

  private:
	Brain *_brain;
};

std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif /* ************************************************************* CAT_H */