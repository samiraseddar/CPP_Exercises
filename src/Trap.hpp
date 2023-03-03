#pragma once
#include "Card.hpp"
#include <string.h>
enum class TrapType
{
    Normal,
    Continuous,
    Counter,

};
std::string to_string(TrapType car)
{
    switch (car)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";

    default:
        return " ";
    }
}
class Trap : public Card
{
public:
    Trap(const std::string &_id, const std::string &_name, TrapType _type) : Card{_id, CardType::Trap}, _type{_type}
    {
        set_name(_name);
        _symbol = u8"罠";
    }
    TrapType get_trap_type()
    {
        // return _symbol;
        return _type;
    }
    std::string get_symbol() const
    {
        return _symbol;
    }

private:
    TrapType _type;
};
