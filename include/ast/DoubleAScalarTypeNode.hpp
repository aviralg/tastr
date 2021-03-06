#ifndef TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_HPP
#define TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr {
namespace ast {

class DoubleAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit DoubleAScalarTypeNode(KeywordNodeUPtr keyword)
        : AScalarTypeNode(std::move(keyword)) {
    }

    ~DoubleAScalarTypeNode() = default;

    DoubleAScalarTypeNode(const DoubleAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    DoubleAScalarTypeNode(DoubleAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    DoubleAScalarTypeNode& operator=(const DoubleAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    DoubleAScalarTypeNode& operator=(DoubleAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<DoubleAScalarTypeNode> clone() const {
        return std::unique_ptr<DoubleAScalarTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

  private:
    virtual DoubleAScalarTypeNode* clone_impl() const override final {
        return new DoubleAScalarTypeNode(*this);
    };

    static const Kind kind_;
};

using DoubleAScalarTypeNodePtr = DoubleAScalarTypeNode*;
using DoubleAScalarTypeNodeUPtr = std::unique_ptr<DoubleAScalarTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_HPP */
