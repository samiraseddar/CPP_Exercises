#pragma once
#include <memory>
#include <utility>
#include "Pokemon.h"
// A ball where a Pokemon sleeps.
class Pokeball
{

public:
    bool empty() const
    {
        return pokem == nullptr;
    }
    void store(PokemonPtr pikachu)
    {
        pokem = std::move(pikachu);
    }
    const Pokemon &pokemon() const
    {
        return *pokem;
    }

private:
    PokemonPtr pokem;
};
