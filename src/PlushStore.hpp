#pragma once
#include <string>
class PlushStore
{
public:
    PlushStore(const std::string &nom) : name{nom}
    {
    }
    std::string get_name() const
    {
        return name;
    }
    int get_wealth_amount() const
    {
        return argent;
    }
    int get_stock_size() const
    {
        return stock;
    }

private:
    std::string name;
    int argent = 0;
    int stock = 0;
};