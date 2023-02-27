#pragma once
#include <vector>
#include "Pokemon.h"
#include <memory>
// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    std::vector<PokemonPtr> &pokemons()
    {
        return _pokemons;
    }
    void transfer(PokemonPtr pok)
    {
        _pokemons.emplace_back(std::move(pok));
    }
    bool empty() const
    {
        return _pokemons.size() == 0;
    }

private:
    std::vector<PokemonPtr> _pokemons;
};
