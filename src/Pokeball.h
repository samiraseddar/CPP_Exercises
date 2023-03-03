#pragma once
#include <memory>
#include "Pokemon.h"
class Pokeball
{

public:
    bool empty() const
    {
        return pokemonptr == nullptr;
    }
    void store(std::unique_ptr<Pokemon> pokim)
    {
        pokemonptr = std::move(pokim);
    }
    const Pokemon &pokemon() const
    {
        return *pokemonptr;
    }

private:
    PokemonPtr pokemonptr;
};
