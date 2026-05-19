// 3. ICharacter — Interface (pure abstract)

// All = 0 → cannot be instantiated, just defines the contract
// equip(AMateria*) → add a spell to inventory
// unequip(int) → remove from slot (does NOT delete it)
// use(int, ICharacter&) → cast spell at slot idx on a target