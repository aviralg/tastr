#ifndef TASTR_AST_TYPE_NODE_H
#define TASTR_AST_TYPE_NODE_H

#include "ast/Node.hpp"

namespace tastr::ast {

class TypeNode: public Node {
  public:
    TypeNode(): Node() {
    }

    virtual ~TypeNode() = default;

    TypeNode(const TypeNode& node): Node(node) {
    }

    TypeNode(TypeNode&& node): Node(std::move(node)) {
    }

    TypeNode& operator=(const TypeNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        return *this;
    }

    TypeNode& operator=(TypeNode&& node) {
        Node::operator=(std::move(node));
        return *this;
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const override = 0;

    std::unique_ptr<TypeNode> clone() const {
        return std::unique_ptr<TypeNode>(this->clone_impl());
    }

    bool is_type_node() const override final {
        return true;
    }

  private:
    virtual TypeNode* clone_impl() const override = 0;
};

using TypeNodePtr = TypeNode*;
using TypeNodeUPtr = std::unique_ptr<TypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_NODE_H */