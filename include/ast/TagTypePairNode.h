#ifndef TASTR_AST_TAGGED_TYPE_H
#define TASTR_AST_TAGGED_TYPE_H

#include "ast/IdentifierNode.h"
#include "ast/Node.h"
#include "ast/TypeNode.h"

#include <memory>
#include <string>

namespace tastr::ast {

class TagTypePairNode final: public Node {
  public:
    explicit TagTypePairNode(std::unique_ptr<IdentifierNode> identifier,
                             std::unique_ptr<TypeNode> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TagTypePairNode() = default;

    TagTypePairNode(const TagTypePairNode& node)
        : identifier_(node.identifier_->clone()), type_(node.type_->clone()) {
    }

    TagTypePairNode(TagTypePairNode&& node)
        : Node(std::move(node))
        , identifier_(std::move(node.identifier_))
        , type_(std::move(node.type_)) {
    }

    TagTypePairNode& operator=(const TagTypePairNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        identifier_ = node.identifier_->clone();
        type_ = node.type_->clone();
        return *this;
    }

    TagTypePairNode& operator=(TagTypePairNode&& node) {
        Node::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        type_ = std::move(node.type_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TagTypePairNode> clone() const {
        return std::unique_ptr<TagTypePairNode>(this->clone_impl());
    }

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

    bool is_tag_type_pair_node() const override final {
        return true;
    }

  private:
    virtual TagTypePairNode* clone_impl() const override final {
        return new TagTypePairNode(*this);
    }

    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
};

using TagTypePairNodePtr = TagTypePairNode*;
using TagTypePairNodeUPtr = std::unique_ptr<TagTypePairNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TAGGED_TYPE_H */