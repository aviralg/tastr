#ifndef R_TYPE_AST_NODE_SCALAR_TYPE_H
#define R_TYPE_AST_NODE_SCALAR_TYPE_H

#include "Type.h"

namespace rtype::ast::node {

class ScalarType: public Type {
  public:
    ScalarType(): Type() {
    }

    virtual ~ScalarType() {
    }

    virtual void accept(rtype::ast::visitor::TypeVisitor& visitor) const = 0;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_SCALAR_TYPE_H */
