
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria    *_tab[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const &rhs);
    MateriaSource &operator=(MateriaSource const &rhs);
    ~MateriaSource();

    virtual void learnMateria(AMateria*);
    virtual AMateria *createMateria(std::string const &type);
};

#endif

// 6. MateriaSource — Concrete spellbook

// Implements IMateriaSource
// Stores up to 4 learned Materia templates
// createMateria("ice") → returns new Ice via clone()