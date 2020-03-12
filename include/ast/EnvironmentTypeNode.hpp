#ifndef TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP
#define TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP

#include "ast/Keyword.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class EnvironmentTypeNode final: public TypeNode {
  public:
    explicit EnvironmentTypeNode(const Keyword& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~EnvironmentTypeNode() = default;

    EnvironmentTypeNode(const EnvironmentTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    EnvironmentTypeNode(EnvironmentTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    EnvironmentTypeNode& operator=(const EnvironmentTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    EnvironmentTypeNode& operator=(EnvironmentTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<EnvironmentTypeNode> clone() const {
        return std::unique_ptr<EnvironmentTypeNode>(this->clone_impl());
    }

    bool is_environment_type_node() const override final {
        return true;
    }

    const Keyword& get_keyword() const {
        return keyword_;
    }

  private:
    virtual EnvironmentTypeNode* clone_impl() const override final {
        return new EnvironmentTypeNode(*this);
    }

    Keyword keyword_;
};

using EnvironmentTypeNodePtr = EnvironmentTypeNode*;
using EnvironmentTypeNodeUPtr = std::unique_ptr<EnvironmentTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP */
