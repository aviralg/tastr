#ifndef TASTR_AST_BYTECODE_TYPE_NODE_HPP
#define TASTR_AST_BYTECODE_TYPE_NODE_HPP

#include "ast/Keyword.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class BytecodeTypeNode final: public TypeNode {
  public:
    explicit BytecodeTypeNode(const Keyword& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~BytecodeTypeNode() = default;

    BytecodeTypeNode(const BytecodeTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    BytecodeTypeNode(BytecodeTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    BytecodeTypeNode& operator=(const BytecodeTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    BytecodeTypeNode& operator=(BytecodeTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<BytecodeTypeNode> clone() const {
        return std::unique_ptr<BytecodeTypeNode>(this->clone_impl());
    }

    bool is_bytecode_type_node() const override final {
        return true;
    }

    const Keyword& get_keyword() const {
        return keyword_;
    }

  private:
    virtual BytecodeTypeNode* clone_impl() const override final {
        return new BytecodeTypeNode(*this);
    }

    Keyword keyword_;
};

using BytecodeTypeNodePtr = BytecodeTypeNode*;
using BytecodeTypeNodeUPtr = std::unique_ptr<BytecodeTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_BYTECODE_TYPE_NODE_HPP */
