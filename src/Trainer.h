#pragma once
#include <string>
#include "PC.h"
#include <array>
#include "Pokeball.h"
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc) : _name{name}, _pc{pc} {};
    const std::string &name() const
    {
        return _name;
    }
    const std::array<Pokeball, 6> &pokeballs() const
    {

        return array;
    }
    void capture(std::unique_ptr<Pokemon> pokemon)
    {
        _pc.transfer(std::move(pokemon));
    }

private:
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> array;
};
