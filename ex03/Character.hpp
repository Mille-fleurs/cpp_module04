
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria    *_slots[4];
public:
    Character();
    Character(const std::string name);
    Character(const Character &rhs);
    Character &operator=(const Character &rhs);
    virtual ~Character();

    virtual std::string const &getName(void) const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif