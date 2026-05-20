
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(AMateria const &other);
    AMateria &operator=(AMateria const &rhs);
    virtual ~AMateria();

    std::string const &getType(void) const;

    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter &target);
};

#endif
