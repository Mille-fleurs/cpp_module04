#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice    &Ice::operator=(const Ice &rhs)
{
    std::cout << "Ice assignment operator called" << std::endl;
    (void)rhs;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone(void) const
{
    return (new Ice());
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}
