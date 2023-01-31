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
    friend std::ostream &operator<<(std::ostream &stream, const Kid &kind)
    {
        stream << kind.name << " has " << kind.age << " euros.";
        return stream;
    }

private:
    std::string name;
    int age;
};
