#pragma once
#include <string>
#include <memory>
class Pokemon
{

public:
    Pokemon(const std::string &name) : _name{name}, _idd{_id++} {};
    Pokemon(const Pokemon &pok) : _name{pok._name}, _idd{_id++} {};

    const std::string &name() const
    {
        return _name;
    }
    int id() const
    {
        return _idd;
    }
    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            _name = other._name;
        }

        return *this;
    }
    PokemonPtr trainer()
    {
        return std::make_unique();
    }

private:
    std::string _name;
    static inline int _id;
    int _idd;
};
using PokemonPtr = std::unique_ptr<Pokemon>;
