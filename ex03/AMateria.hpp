
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMatria
{
protected
    std::string _type;
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(AMateria const &rhs);
    AMateria &operator=(AMateria const &rhs);
    virtual ~AMateria();

    std::string const &getType(void) const;

    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter &target);
}

#endif

// AMateria — Abstract base for all spells
// Has a type (string like "ice" or "cure")
// clone() = 0 → each spell knows how to copy itself
// use() → prints the spell effect targeting a character