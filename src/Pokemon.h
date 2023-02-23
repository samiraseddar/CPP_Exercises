#pragma once

#include <string>

// A creature that is cute and can fight other ones.
class Pokemon
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
};
