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

    me->use(0, *bob);
    me->use(0, *bob);

    delete bob;
    delete me;
    delete src;

    return (0);
}

// #include "Ice.hpp"
// #include "Cure.hpp"
// #include "Character.hpp"
// #include "MateriaSource.hpp"
 
// int main(void)
// {
//     // --- Subject's required test ---
//     std::cout << "\n--- Subject test ---\n" << std::endl;
//     IMateriaSource *src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
 
//     ICharacter *me = new Character("me");
 
//     AMateria *tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
 
//     ICharacter *bob = new Character("bob");
//     me->use(0, *bob);   // * shoots an ice bolt at bob *
//     me->use(1, *bob);   // * heals bob's wounds *
 
//     delete bob;
//     delete me;
//     delete src;
 
//     // --- Full inventory (slots 0-3) + overflow ---
//     std::cout << "\n--- Full inventory + overflow ---\n" << std::endl;
//     Character hero("hero");
//     hero.equip(new Ice());
//     hero.equip(new Cure());
//     hero.equip(new Ice());
//     hero.equip(new Cure());
//     hero.equip(new Ice()); // 5th: should be ignored, not crash
 
//     // --- unequip does NOT delete ---
//     std::cout << "\n--- Unequip test ---\n" << std::endl;
//     AMateria *saved;
//     Character alice("alice");
//     saved = new Ice();
//     alice.equip(saved);
//     alice.unequip(0);       // slot 0 is now NULL, saved still valid
//     alice.use(0, alice);    // nothing should happen
//     delete saved;           // we own it now, we delete it
 
//     // --- Deep copy of Character ---
//     std::cout << "\n--- Deep copy test ---\n" << std::endl;
//     Character original("original");
//     original.equip(new Ice());
//     original.equip(new Cure());
//     {
//         Character copy(original);       // copy constructor
//         copy.use(0, copy);              // should work independently
//     }                                   // copy destroyed here, original unaffected
//     original.use(0, original);          // original still valid
 
//     // --- Assignment operator deep copy ---
//     std::cout << "\n--- Assignment test ---\n" << std::endl;
//     Character a("a");
//     a.equip(new Ice());
//     Character b("b");
//     b = a;                  // deep copy: b gets its own Ice
//     b.use(0, b);            // works
//     a.use(0, a);            // a unaffected
 
//     // --- Invalid index ---
//     std::cout << "\n--- Invalid index ---\n" << std::endl;
//     Character guard("guard");
//     guard.use(-1, guard);   // nothing, no crash
//     guard.use(4, guard);    // nothing, no crash
//     guard.unequip(-1);      // nothing, no crash
 
//     // --- Unknown materia type ---
//     std::cout << "\n--- Unknown materia ---\n" << std::endl;
//     MateriaSource ms;
//     ms.learnMateria(new Ice());
//     AMateria *unknown = ms.createMateria("fire"); // should return NULL/0
//     if (!unknown)
//         std::cout << "Unknown materia correctly returned NULL" << std::endl;
 
//     std::cout << "\n--- End ---\n" << std::endl;
//     return (0);
// }
 
