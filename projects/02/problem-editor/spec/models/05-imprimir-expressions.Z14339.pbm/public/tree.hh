#ifndef TREE_HH
#define TREE_HH

#include <memory>
#include <vector>
#include "assert.hh"

namespace pro2 {

/**
 * @file Tree.hh
 * @class Tree
 * @brief A class representing a tree with any number of children.
 */
template <typename T>
class Tree {
 private:
    /**
     * @brief Struct that holds the node's information
     */
    struct Node_ {
        T value_;
        std::vector<std::shared_ptr<Node_>> children_;

        Node_(const T& value) : value_(value) {}

        Node_(const T& value, std::vector<std::shared_ptr<Node_>> children)
            : value_(value), children_(std::move(children)) {}
    };

    /**
     * @brief Pointer to the node of the tree
     */
    std::shared_ptr<Node_> pnode_;

    /**
     * @brief Constructs a tree from a node pointer.
     */
    Tree(std::shared_ptr<Node_> pnode) : pnode_(pnode) {}

 public:
    /**
     * @brief Constructs an empty tree. Θ(1).
     */
    Tree() : pnode_(nullptr) {}

    /**
     * @brief Constructs a tree as a copy of another tree. Θ(1).
     */
    Tree(const Tree& tree) {
        pnode_ = tree.pnode_;
    }

    /**
     * @brief Constructs a tree with a value `x` and no children. Θ(1).
     */
    explicit Tree(const T& value) {
        pnode_ = std::make_shared<Node_>(value);
    }

    /**
     * @brief Constructs a tree with a value `x` and a list of `children`. Θ(1).
     */
    explicit Tree(const T& value, const std::vector<Tree>& children) {
        std::vector<std::shared_ptr<Node_>> children_pnodes;
        for (const auto& child : children) {
            children_pnodes.push_back(child.pnode_);
        }
        pnode_ = std::make_shared<Node_>(value, children_pnodes);
    }

    /**
     * @brief Assigns the tree `other` to this tree, returns itself. Θ(1).
     */
    Tree& operator=(const Tree& other) {
        pnode_ = other.pnode_;
        return *this;
    }

    /**
     * @brief Returns `true` if this tree is empty, `false` otherwise. Θ(1).
     */
    bool empty() const {
        return pnode_ == nullptr;
    }

    /**
     * @brief Returns the i-th child subtree of this tree. Aborts if empty. Θ(1).
     */
    Tree child(int i) const {
        assert(not empty(), "Tree::child cridat sobre un arbre buit");
        assert(i >= 0 && i < pnode_->children_.size(), "Tree::child índex fora de rang");
        return Tree(pnode_->children_[i]);
    }

    /**
     * @brief Returns the number of children of this tree. Aborts if empty. Θ(1).
     */
    int num_children() const {
        assert(not empty(), "Tree::num_children cridat sobre un arbre buit");
        return pnode_->children_.size();
    }

    /**
     * @brief Returns the value of this tree. Aborts if empty. Θ(1).
     */
    const T& value() const {
        assert(not empty(), "Tree::value cridat sobre un arbre buit");
        return pnode_->value_;
    }
};

}  // namespace pro2

#endif