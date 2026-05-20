
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : ICharacter(), _name("default")
{
    std::cout << "Character default constructor called" << std::endl;
    _slots[0] = NULL;
    _slots[1] = NULL;
    _slots[2] = NULL;
    _slots[3] = NULL;
};

Character::Character(const std::string name) : ICharacter(), _name(name)
{
    std::cout << "Character " << _name << " constructor called" << std::endl;
    _slots[0] = NULL;
    _slots[1] = NULL;
    _slots[2] = NULL;
    _slots[3] = NULL;
}

Character::Character(const Character &other) : ICharacter(other)
{
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
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    _slots[idx] = NULL;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
        return ;
    if (_slots[idx] == NULL)
        _slots[idx]->use(target);
}

