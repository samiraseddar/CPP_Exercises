#pragma once
#include "PC.h"
#include <string>
// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc) : _name{name}, _pc{pc} {}
    const std::string &name() const
    {
        return _name;
    }
    const std::vector<PC> &pokeballs() const
    {
        return pcs;
    }
    void capture(PokemonPtr pok)
    {
        _pc.transfer(std::move(pok));
    }

private:
    std::string _name;
    PC &_pc;
    std::vector<PC> pcs{6};
};
