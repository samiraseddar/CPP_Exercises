#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <map>
#include <memory>
class ObjectNode : public Node
{

public:
    NodeKind                           kind() const { return NodeKind::OBJECT; }
    std::string                        print() const { return "{}"; }
    int                                child_count() const override { return 0; }
    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); }
    void insert(const std::string& s, NodePtr nodeptr) { _dic.emplace(s, std::move(nodeptr)); }

private:
    std::map<std::string, NodePtr> _dic;
    int                            count;
};
