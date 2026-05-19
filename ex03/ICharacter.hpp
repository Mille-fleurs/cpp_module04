
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

#endif

// 3. ICharacter — Interface (pure abstract)
// All = 0 → cannot be instantiated, just defines the contract
// equip(AMateria*) → add a spell to inventory
// unequip(int) → remove from slot (does NOT delete it)
// use(int, ICharacter&) → cast spell at slot idx on a target