#pragma once
#include <iostream>
#include <string>
class Kid
{

public:
    Kid(const std::string &nom, int ag) : name{nom}, age{ag}
    {
    }
    std::string get_name() const
    {
        return name;
    }
    int get_money() const
    {
        return age;
    }

private:
    std::string name;
    int age;
};
