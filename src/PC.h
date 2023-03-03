#pragma once
#include "Pokemon.h"
#include <vector>
class PC
{
public:
    const std::vector<PokemonPtr> &pokemons() const
    {
        return pcs;
    }
    void transfer(PokemonPtr pok)
    {
        pcs.push_back(std::move(pok));
    }

private:
    std::vector<PokemonPtr> pcs;
};
