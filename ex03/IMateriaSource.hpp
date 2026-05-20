
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0; 
};

#endif

// 5. IMateriaSource — Interface (pure abstract)
// learnMateria(AMateria*) → stores a spell template (max 4)
// createMateria(string) → finds the matching template and returns a clone