#ifndef TASTR_AST_NODE_NO_NA_TYPE_H
#define TASTR_AST_NODE_NO_NA_TYPE_H

#include "CompositeType.h"
#include "VectorType.h"

#include <memory>

namespace tastr::ast::node {

class NoNaType final: public CompositeType {
  public:
    NoNaType(std::unique_ptr<VectorType> inner_type)
        : CompositeType(), inner_type_(std::move(inner_type)) {
    }

    ~NoNaType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;

    const tastr::ast::node::VectorType& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<tastr::ast::node::VectorType> inner_type_;
};

using NoNaTypePtr = NoNaType*;
using NoNaTypeUPtr = std::unique_ptr<NoNaType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_NO_NA_TYPE_H */
