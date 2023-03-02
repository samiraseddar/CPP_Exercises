#pragma once
#include "InstanceCounter.hpp"

#include <memory>
#include <string>

class Node : public InstanceCounter
{
public:
    virtual std::string print() const       = 0;
    virtual int         child_count() const = 0;
};
using NodePtr = std::unique_ptr<Node>;
