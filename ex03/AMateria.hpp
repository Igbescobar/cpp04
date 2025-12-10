#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class	ICharacter;

class AMateria
{
  protected:
	std::string _type;

  public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria();

	AMateria &operator=(AMateria const &rhs);

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

  private:
};

#endif /* ******************************************************** AMATERIA_H */