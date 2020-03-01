#ifndef TASTR_AST_COMPLEX_TYPE_H
#define TASTR_AST_COMPLEX_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class ComplexScalarTypeNode final: public ScalarTypeNode {
  public:
    ComplexScalarTypeNode(): ScalarTypeNode() {
    }

    ComplexScalarTypeNode(const ComplexScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    ~ComplexScalarTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ComplexScalarTypeNode> clone() const {
        return std::unique_ptr<ComplexScalarTypeNode>(this->clone_impl());
    }

    bool is_complex_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual ComplexScalarTypeNode* clone_impl() const override final {
        return new ComplexScalarTypeNode(*this);
    };
};

using ComplexScalarTypeNodePtr = ComplexScalarTypeNode*;
using ComplexScalarTypeNodeUPtr = std::unique_ptr<ComplexScalarTypeNode>;
} // namespace tastr::ast

#endif /* TASTR_AST_COMPLEX_TYPE_H */