#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>
class StringLeaf : public Leaf
{

public:
    StringLeaf(const std::string& data)
        : _data { data } {};
    NodeKind           kind() const { return NodeKind::STRING; }
    std::string        print() const { return "\"" + _data + "\""; }
    const std::string& data() const { return _data; }
    static NodePtr     make_ptr(const std::string& cc) { return std::make_unique<StringLeaf>(cc); }
    int                child_count() const override { return 0; }

private:
    std::string _data;
};
