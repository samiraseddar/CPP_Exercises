#pragma once
#include "Monster.hpp"
#include "Card.hpp"
#include <string>
enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind,

};

std::string to_symbol(Attribute att)
{
    switch (att)
    {
    case Attribute::Dark:
        return u8"闇";
    case Attribute::Divine:
        return u8"神";
    case Attribute::Earth:
        return u8"地";
    case Attribute::Fire:
        return u8"炎";
    case Attribute::Light:
        return u8"光";
    case Attribute::Water:
        return u8"水";

    case Attribute::Wind:
        return u8"風";
    default:
        return " ";
    }
}

class Monster : public Card
{

public:
    Monster(const std::string &_id, const std::string &_name2, Attribute _attribute, const std::string &_name3, int _atk, int _def) : Card{_id, CardType::Monster},
                                                                                                                                      _attribute{_attribute}, _name3{_name3}, _atk{_atk}, _def{_def} { set_name(_name2); }
    Attribute get_attribute() const
    {
        return _attribute;
    }
    int get_atk() const
    {
        return _atk;
    }
    int get_def() const
    {
        return _def;
    }
    void set_description(const std::string des)
    {
        Card::set_description(des);
    }
    std::string get_description() const
    {
        return "[" + _name3 + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }
    std::string get_symbol() const
    {
        return to_symbol(_attribute);
    }

private:
    Attribute _attribute;
    std::string _name3;
    int _atk;
    int _def;
};
