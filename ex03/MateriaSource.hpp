
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
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &rhs);
    ~MateriaSource();

    virtual void learnMateria(AMateria*);
    virtual AMateria *createMateria(std::string const &type);
};

#endif