
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    std::cout << "\n--- Subject test ---\n";

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
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "\n--- Full inventory + overflow ---\n";

    Character lily("lily");
    lily.equip(new Ice());
    lily.equip(new Cure());
    lily.equip(new Cure());
    lily.equip(new Ice());
    lily.equip(new Cure());
    for (int i = 0; i < 4; i++)
    {
        AMateria *m = lily.getMateria(i);
        if (m)
            std::cout << m->getType() << std::endl;
        else
            std::cout << "empty" << std::endl;
        delete m;
    }

    std::cout << "\n--- Unequipped test ---\n";

    Character erica("erica");
    tmp = new Ice();
    erica.equip(tmp);
    erica.unequip(0);
    erica.use(0, erica);
    delete tmp;
    std::cout << "Unequip test passed: Materia was not deleted." << std::endl;
    
    std::cout << "\n--- Deep copy test ---\n";

    Character original("original");
    original.equip(new Ice());
    original.equip(new Cure());
    {
        Character copy(original);
        copy.use(0, copy);
    }
    original.use(0, original);

    std::cout << "\n--- Assignment test ---\n";

    Character one("one");
    one.equip(new Ice());
    Character two("two");
    two = one;
    two.use(0, two);
    one.use(0, one);

    std::cout << "\n--- Invalid index ---\n";

    Character momo("momo");
    momo.use(-1, momo);
    momo.use(4, momo);
    momo.unequip(-1);
    std::cout << "Invalid index test passed if no crash occurred" << std::endl;
 
    std::cout << "\n--- Unknown materia ---\n";

    MateriaSource ms;
    ms.learnMateria(new Cure());
    AMateria *unknown = ms.createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia correctly returned NULL" << std::endl;

    std::cout << "\n--- End of main ---\n";
    return (0);
}
