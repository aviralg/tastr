#ifndef TASTR_AST_TOP_LEVEL_NODE_HPP
#define TASTR_AST_TOP_LEVEL_NODE_HPP

#include "EofNode.hpp"
#include "Node.hpp"
#include "TypeDeclarationNode.hpp"

#include <string>
#include <vector>

namespace tastr {
namespace ast {

class TopLevelNode final: public Node {
  public:
    typedef std::vector<std::unique_ptr<TypeDeclarationNode>> sequence_t;

    typedef sequence_t* sequence_ptr_t;

    typedef std::unique_ptr<sequence_t> sequence_uptr_t;

    typedef typename sequence_t::iterator iterator;

    typedef typename sequence_t::reverse_iterator reverse_iterator;

    typedef typename sequence_t::const_iterator const_iterator;

    typedef typename sequence_t::const_reverse_iterator const_reverse_iterator;

    explicit TopLevelNode(const std::string& name)
        : name_(name), eof_node_(nullptr) {
    }

    ~TopLevelNode() = default;

    TopLevelNode(const TopLevelNode& node): Node(node), name_(node.name_) {
        for (int index = 0; index < node.size(); ++index) {
            type_declarations_.push_back(node.at(index).clone());
        }
    }

    TopLevelNode(TopLevelNode&& node)
        : Node(std::move(node))
        , name_(std::move(node.name_))
        , type_declarations_(std::move(node.type_declarations_)) {
    }

    TopLevelNode& operator=(const TopLevelNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        name_ = node.name_;
        for (int index = 0; index < node.size(); ++index) {
            type_declarations_.push_back(node.at(index).clone());
        }
        return *this;
    }

    TopLevelNode& operator=(TopLevelNode&& node) {
        Node::operator=(std::move(node));
        name_ = std::move(node.name_);
        type_declarations_ = std::move(node.type_declarations_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TopLevelNode> clone() const {
        return std::unique_ptr<TopLevelNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const sequence_t& get_type_declarations() const {
        return type_declarations_;
    }

    sequence_t& get_type_declarations() {
        return type_declarations_;
    }

    size_t size() const {
        return type_declarations_.size();
    }

    bool is_empty() const {
        return type_declarations_.empty();
    }

    const TypeDeclarationNode& at(int index) const {
        return *type_declarations_.at(index).get();
    }

    TypeDeclarationNode& at(int index) {
        return *type_declarations_.at(index).get();
    }

    const EofNode& get_eof_node() const {
        return *eof_node_.get();
    }

    void set_eof_node(EofNodeUPtr& node) {
        eof_node_.reset(node.release());
        node.reset(nullptr);
    }

  private:
    virtual TopLevelNode* clone_impl() const override final {
        return new TopLevelNode(*this);
    }

    std::string name_;
    sequence_t type_declarations_;
    EofNodeUPtr eof_node_;

    static const Kind kind_;
};

using TopLevelNodePtr = TopLevelNode*;
using TopLevelNodeUPtr = std::unique_ptr<TopLevelNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_TOP_LEVEL_NODE_HPP */
