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
    int get_stock_size()
    {
        return size;
    }
    float get_wealth_amount() const
    {
        return argent;
    }
    int get_stock_size() const
    {
        return stock;
    }
    void loan(const float &a)
    {
        argent += a;
    }
    int get_experience()
    {
        return size;
    }
    float make_plush(const float &a)
    {
        if (argent >= a)
        {
            size++;
            argent = argent - a;
        }
        if (argent < 0)
        {
            argent = 0;
        }
        return argent;
    }
    float get_debt_amount()
    {
        return argent + (argent * 0.10);
        ;
    }

private:
    std::string name;
    float argent = 0.0;
    int stock = 0;
    int size = 0;
};