#pragma once
#include "Leaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>
class IntLeaf : public Leaf
{
public:
    IntLeaf(int _data)
        : _data { _data } {};
    NodeKind                        kind() const { return NodeKind::INT; }
    std::string                     print() const override { return std::to_string(_data); }
    int                             data() const { return _data; }
    int                             child_count() const override { return 0; }
    static std::unique_ptr<IntLeaf> make_ptr(int i) { return std::make_unique<IntLeaf>(i); }

private:
    int _data;
};
