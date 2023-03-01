#pragma once
#include <string>
#include "Card.hpp"
enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field,

};
std::string to_string(SpellType car)
{
    switch (car)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    default:
        return " ";
    }
}
class Spell : public Card
{
public:
    Spell(const std::string &_id, const std::string &_name, SpellType _spell_type) : Card{_id, CardType::Spell}, _spell_type{_spell_type}
    {
        set_name(_name);
        _symbol = u8"魔";
    }
    SpellType get_spell_type()
    {
        return _spell_type;
    }
    std::string get_trap_type() const
    {
        return _symbol;
    }
    std::string get_symbol() const
    {
        return _symbol;
    }

private:
    SpellType _spell_type;
};
