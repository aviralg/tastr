#include "ast/node/VarargType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::VarargType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}