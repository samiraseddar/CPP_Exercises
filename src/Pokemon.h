#pragma once

#include <string>
#include <iostream>
#include <memory>
// A creature that is cute and can fight other ones.
/*class Pokemon
{
public:
    Pokemon(std::string_view nom) : nam{nom}, _id{idd++}
    {
    }
    Pokemon(const Pokemon &pokemon) : nam{pokemon.nam}, _id{idd++}
    {
    }
    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            nam = other.nam;
        }

        return *this;
    }
    std::string name() const
    {
        return nam;
    }
    int id() const
    {
        return _id;
    }

private:
    std::string nam;
    static inline int idd = 0;
    int _id;
};*/
class Pokemon
{

public:
    Pokemon(std::string name) : nam{name}, _idd{idd++} {};
    Pokemon(const Pokemon &pok) : nam{pok.nam}, _idd{idd++} {};

    std::string name() const
    {
        return nam;
    }
    int id() const
    {
        return _idd;
    }
    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            nam = other.nam;
        }

        return *this;
    }

private:
    std::string nam;
    static inline int idd;
    int _idd;
};
using PokemonPtr = std::unique_ptr<Pokemon>;
