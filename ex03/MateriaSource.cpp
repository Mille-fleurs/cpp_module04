
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _tab[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
        _tab[i] = NULL;
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _tab[i];
            _tab[i] = NULL;
            if (rhs._tab[i] != NULL)
                _tab[i] = rhs._tab[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _tab[i];
    std::cout << "MateriaSoource destructor called" << std::endl;
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_tab[i] == NULL)
        {
            _tab[i] = m;
            return ;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_tab[i] && type.compare(_tab[i]->getType()) == 0)
            return (_tab[i]->clone());
    }
    return (0);
}
