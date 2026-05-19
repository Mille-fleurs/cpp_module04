#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// AMateria        = base class for spells
// Ice / Cure      = real spells
// ICharacter      = interface for characters
// Character       = real character with inventory[4]
// IMateriaSource  = interface for spellbook
// MateriaSource   = real spellbook that learns and creates spells

int main(void)
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0. *bob);
    me->use(0, *bob);

    delete bob;
    delete me;
    delete src;

    return (0);
}
