
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("default")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
};

Character::Character(const std::string name) : _name(name)
{
    std::cout << "Character " << _name << " constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
    std::cout << "Charactyer copy constructor called" << std::endl;
    *this = other;
}

Character   &Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            delete _slots[i];
            _slots[i] = NULL;
            if (rhs._slots[i] != NULL)
                _slots[i] = rhs._slots[i]->clone();
        }
    }
    std::cout << "Character assignment operator called" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _slots[i];
    std::cout << "Character destrcutor called" << std::endl;
}

std::string const &Character::getName(void) const
{
    return (_name);
}

void    Character::equip(AMateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m;
            return ;
        }
    }
    delete m;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || _slots[idx] == NULL)
        return ;
    _slots[idx] = NULL;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
        return ;
    if (_slots[idx] != NULL)
        _slots[idx]->use(target);
}

AMateria *Character::getMateria(int idx) const
{
    if (idx < 0 || idx >= 4)
        return (0);
    return (_slots[idx]);
}