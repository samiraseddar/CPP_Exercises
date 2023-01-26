#pragma once
class Plush
{
public:
    Plush() = default;
    Plush(int a) : cost{a}
    {
    }
    void set_cost(int b)
    {
        cost = b;
    }

    int get_cost() const
    {
        return cost;
    }

private:
    int cost = 10;
};
