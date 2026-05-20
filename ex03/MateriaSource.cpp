
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    _tab[0] = NULL;
    _tab[1] = NULL;
    _tab[2] = NULL;
    _tab[3] = NULL;
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
    int i;

    i = 0;
    if (m == NULL)
    {
        std::cout << "Null materia." << std::endl;
        return ;
    }
    while (i < 4 && _tab[i] != NULL)
        i++;
    if (i == 4)
    {
        std::cout << "Materia source full." << std::endl;
        return ;
    }
    _tab[i] = m->clone();
    delete m;
    std::cout << "Materia learned" << std::endl;
    if (i == 3)
        std::cout << "MateriaSource now full." << std::endl;
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    int i;
    AMateria    *copy;

    i = 0;
    while (i < 4 && _tab[i] != NULL && type.compare(_tab[i]->getType()) != 0)
        i++;
    if (i == 4 || _tab[i] == NULL)
    {
        std::cout << "Unknown materia type." << std::endl;
        return (0);
    }
    copy = _tab[i]->clone();
    return (copy);
}