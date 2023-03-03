#pragma once
#include <string>
enum class CardType
{
    Monster,
    Spell,
    Trap,

};

std::string to_string(CardType car)
{
    switch (car)
    {
    case CardType::Monster:
        return "Monster";
    case CardType::Spell:
        return "Spell";
    case CardType::Trap:
        return "Trap";

    default:
        return " ";
    }
}

class Card
{
public:
    Card(const std::string &_id, CardType _type) : _id{_id}, _type{_type} {};
    std::string get_id() const
    {
        return _id;
    }
    CardType get_type() const
    {
        return _type;
    }
    std::string get_name() const
    {
        return _name;
    }
    std::string get_description() const
    {
        return _description;
    }
    void set_name(const std::string &nom)
    {
        _name = nom;
    }
    void set_description(const std::string des)
    {
        _description = des;
    }
    std::string get_description()
    {
        return _description;
    }
    std::string get_trap_type() const
    {
        return _symbol;
    }

protected:
    std::string _symbol;

private:
    std::string _id;
    CardType _type;
    std::string _name;
    std::string _description;
};
