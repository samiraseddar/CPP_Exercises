#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>
#include <vector>
class ArrayNode : public Node
{
public:
    NodeKind    kind() const { return NodeKind::ARRAY; }
    std::string print() const
    {
        if (childs.size() == 0)
        {
            return "[]";
        }
        std::string s = "[" + childs[0]->print();
        for (std::size_t i = 1; i < childs.size(); i++)
        {
            s = s + "," + childs[i]->print();
        }
        s = s + "]";
        return s;
    }
    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); }
    int                               child_count() const override { return childs.size(); }
    void                              push_back(NodePtr nodeptr) { childs.push_back(std::move(nodeptr)); }

private:
    std::vector<NodePtr> childs;
};
