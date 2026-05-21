
#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria " << _type << " constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

AMateria    &AMateria::operator=(AMateria const &rhs)
{
    std::cout << "AMateria assignment operator called" <<std::endl;
    (void)rhs;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const   &AMateria::getType(void) const
{
    return (_type);
}

void    AMateria::use(ICharacter &target)
{
    (void)target;
}
