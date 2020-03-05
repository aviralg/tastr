#include "ast/CharacterScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::CharacterScalarTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::CharacterScalarTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
