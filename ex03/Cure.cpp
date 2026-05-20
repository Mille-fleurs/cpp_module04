#include "Cure.hpp"

Cure::Cure() : AMateria()
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure    &Cure::operator=(const Cure &rhs)
{
    std::cout << "Cure assignment operator called" << std::endl;
    (void)rhs;
    return (*this);
}

AMateria *Cure::clone(void) const
{
    AMateria    *copy;

    copy = new Cure;
    return (copy);
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
