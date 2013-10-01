#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream>
#include <sstream>
#include <functional>

template <typename T>
class Node {
public:
    explicit Node()
        :value_(), lch_(NULL), rch_(NULL)
    { }

    explicit Node(const T& value, Node<T> *lch=NULL, Node<T> *rch=NULL)
        :value_(value), lch_(lch), rch_(rch)
    { }

    ~Node() { }

    const T&
    value() const
    { return this->value_; }

    Node<T> *
    left_child() const
    { return this->lch_; }

    void
    left_child(Node<T> *lch)
    { this->lch_ = lch; }

    Node<T> *
    right_child() const
    { return this->rch_; }

    void
    right_child(Node<T> *rch)
    { this->rch_ = rch; }

    friend std::ostream
    operator<<(std::ostream& os, const Node<T>& node)
    { return os << node.value(); }
private:
    Node(const Node<T>& node);
    const Node<T>&
    operator=(const Node<T>& node);
    
    T value_;
    Node<T> *lch_;
    Node<T> *rch_;
};

template <typename T>
class BinarySearchTree {
public:
    explicit BinarySearchTree()
        :root_(NULL)
    { }

    explicit BinarySearchTree(const T& root_val)
        :root_(new Node<T>(root_val))
    { }

    explicit BinarySearchTree(const T values[], const size_t& size)
        :root_(NULL)
    {
        if (size > 0) {
            this->root_ = new Node<T>(values[0]);
            for (int i = 1; i < size; ++i) {
                this->insert(values[i]);
            }
        }
    }
    
    BinarySearchTree(const BinarySearchTree<T>& tree)
        :root_(NULL)
    { this->root_ = new_nodes(this->root_, tree.root_); }
    
    const BinarySearchTree&
    operator=(const BinarySearchTree& tree)
    {
        if (this != &tree) {
            BinarySearchTree tmp(tree);
            Node<T> *p = tmp.proot();
            tmp.proot(this->root_);
            this->root_ = p;
        }
        return *this;
    }

    ~BinarySearchTree()
    {
        auto del_fun = std::bind(&BinarySearchTree<T>::del_node,
                                 this, std::placeholders::_1);
        postorder(this->root_, del_fun);
    }

    Node<T> *
    proot() const
    { return this->root_; }

    void
    proot(Node<T> *root)
    { this->root_ = root; }

    const T&
    root() const
    { return this->root_->value(); }

    bool
    is_empty() const
    { return this->root_ == NULL; }

    void
    insert(const T& value)
    {
        Node<T> *p = this->root_;

        if (p == NULL) {
            this->root_ = new Node<T>(value);
            return;
        }
        while (p != NULL) {
            if (value < p->value()) {
                if (p->left_child() == NULL) {
                    Node<T> *node = new Node<T>(value);
                    p->left_child(node);
                    break;
                } else {
                    p = p->left_child();
                }
            } else if (value == p->value()) {
                Node<T> *node = new Node<T>(value, p->left_child());
                p->left_child(node);
                break;
            } else {
                if (p->right_child() == NULL) {
                    Node<T> *node = new Node<T>(value);
                    p->right_child(node);
                    break;
                } else {
                    p = p->right_child();
                }
            }
        }
    }

    std::string
    inorder_travel() const
    {
        std::string result = inorder(this->root_);
        result.erase(0, 1);
        result[0] = '[';
        result.append(1, ']');
        
        return result;
    }
private:
    Node<T> *root_;
    
    std::string
    inorder(Node<T> *root) const
    {
        std::string result = "";
        std::string seperator = ", ";
        if (root != NULL) {
            if (root->left_child() != NULL) {
                result += inorder(root->left_child());
            }
            std::stringstream ss;
            ss << seperator << root->value();
            result += ss.str();
            if (root->right_child() != NULL) {
                result += inorder(root->right_child());
            }
        }
        return result;
    }

    void
    postorder(Node<T> *root, const std::function<void(Node<T> *)>& func)
    {
        if (root != NULL) {
            if (root->left_child() != NULL) {
                postorder(root->left_child(), func);
            }
            if (root->right_child() != NULL) {
                postorder(root->right_child(), func);
            }
            func(root);
        }
    }

    void
    del_node(Node<T> *node)
    {
        if (node != NULL) {
            delete node;
        }
    }

    void
    inorder(Node<T> *root, const std::function<void(const T&)>& func)
    {

    }

    Node<T> *
    new_nodes(Node<T> *dest, const Node<T> *src)
    {
        if (src != NULL) {
            if (dest == NULL) {
                dest = new Node<T>(src->value());
            }
            if (src->left_child() != NULL) {
                dest->left_child(new_nodes(dest->left_child(),
                                           src->left_child()));
            }
            if (src->right_child() != NULL) {
                dest->right_child(new_nodes(dest->right_child(),
                                            src->right_child()));
            }
        }
        return dest;
    }
};

#endif /* _BINARY_SEARCH_TREE_H_ */
