#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream>
#include <sstream>
#include <functional>
#include <vector>

template <typename T>
class Node {
public:
    explicit Node()
        :value_(), lch_(NULL), rch_(NULL), parent_(NULL)
    { }

    explicit Node(const T& value, Node<T> *lch=NULL,
                  Node<T> *rch=NULL, Node<T> *parent=NULL)
        :value_(value), lch_(lch), rch_(rch), parent_(parent)
    { }

    ~Node() { }

    const T&
    value() const
    { return this->value_; }

    void
    value(const T& v)
    { this->value_ = v; }

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

    Node<T> *
    parent() const
    { return this->parent_; }
    
    void
    parent(Node<T> *parent)
    { this->parent_ = parent; }

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
    Node<T> *parent_;
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
                    node->parent(p);
                    p->left_child(node);
                    break;
                } else {
                    p = p->left_child();
                }
            } else if (value == p->value()) {
                Node<T> *node = new Node<T>(value, p->left_child());
                node->left_child()->parent(node);
                node->parent(p);
                p->left_child(node);
                break;
            } else {
                if (p->right_child() == NULL) {
                    Node<T> *node = new Node<T>(value);
                    node->parent(p);
                    p->right_child(node);
                    break;
                } else {
                    p = p->right_child();
                }
            }
        }
    }

    std::string
    inorder_string() const
    {
        std::string result = this->inorder_str(this->root_);
        if (result != "") {
            result.erase(0, 1);
            result[0] = '[';        
        } else {
            result.append(1, '[');
        }
        result.append(1, ']');
        
        return result;
    }

    std::vector<T>
    retrieve(const T& key)
    { return this->search(this->root_, key); }

    void
    remove(const T& key)
    { this->delete_nodes(this->root_, key, false); }
private:
    Node<T> *root_;
    
    std::string
    inorder_str(Node<T> *root) const
    {
        std::string result = "";
        std::string seperator = ", ";
        if (root != NULL) {
            if (root->left_child() != NULL) {
                result += this->inorder_str(root->left_child());
            }
            std::stringstream ss;
            ss << seperator << root->value();
            result += ss.str();
            if (root->right_child() != NULL) {
                result += this->inorder_str(root->right_child());
            }
        }
        return result;
    }

    void
    postorder(Node<T> *root, const std::function<void(Node<T> *)>& func)
    {
        if (root != NULL) {
            if (root->left_child() != NULL) {
                this->postorder(root->left_child(), func);
            }
            if (root->right_child() != NULL) {
                this->postorder(root->right_child(), func);
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
    inorder(Node<T> *root, const std::function<void(void)>& func)
    {
        if (root != NULL) {
            if (root->left_child() != NULL) {
                this->inorder(root->left_child(), func);
            }
            func(root);
            if (root->right_child() != NULL) {
                this->inorder(root->right_child(), func);
            }
        }
    }

    void
    preorder(Node<T> *root, const std::function<void(void)>& func)
    {
        if (root != NULL) {
            func(root);
            if (root->left_child() != NULL) {
                this->preorder(root->left_child(), func);
            }
            if (root->right_child() != NULL) {
                this->preorder(root->right_child(), func);
            }
        }
    }
    
    Node<T> *
    new_nodes(Node<T> *dest, const Node<T> *src)
    {
        if (src != NULL) {
            if (dest == NULL) {
                dest = new Node<T>(src->value());
            }
            if (src->left_child() != NULL) {
                Node<T> *node = new_nodes(dest->left_child(),
                                          src->left_child());
                node->parent(dest);
                dest->left_child(node);
            }
            if (src->right_child() != NULL) {
                Node<T> *node = new_nodes(dest->right_child(),
                                          src->right_child());
                node->parent(dest);
                dest->right_child(node);
            }
        }
        return dest;
    }

    std::vector<T>
    search(Node<T> *root, const T& key)
    {
        std::vector<T> values;
        if (root != NULL) {
            if (key == root->value()) {
                values.push_back(root->value());
            }
            if (root->left_child() != NULL &&
                root->left_child()->value() > key) {
                return values;
            }
            if (key <= root->value()) {
                std::vector<T> tmp =
                    this->search(root->left_child(), key);
                values.reserve(values.size() + tmp.size());
                values.insert(values.end(), tmp.begin(), tmp.end());
            }
            if (root->right_child() != NULL &&
                root->right_child()->value() < key) {
                return values;
            }
            if (key > root->value()) {
                std::vector<T> tmp =
                    this->search(root->right_child(), key);
                values.reserve(values.size() + tmp.size());             
                values.insert(values.end(), tmp.begin(), tmp.end());
            }
        }
        return values;
    }

    void
    delete_nodes(Node<T> *root, const T& key, bool single)
    {
        if (root != NULL) {
            if (key < root->value()) {
                this->delete_nodes(root->left_child(), key, single);
            } else if (key > root->value()) {
                this->delete_nodes(root->right_child(), key, single);
            } else {
                while (key == root->value()) {
                    if (root->left_child() != NULL &&
                        root->right_child() != NULL) {
                        Node<T> *predecessor =
                            this->mini_node(root->right_child());
                        root->value(predecessor->value());
                        this->delete_nodes(predecessor, predecessor->value(),
                                           true);
                    } else if (root->left_child() != NULL) {
                        if (root == this->root_) {
                            this->root_ = root->left_child();
                        } else if (root->parent()->left_child() == root) {
                            root->parent()->left_child(root->left_child());
                            root->left_child()->parent(root->parent());
                        } else {
                            root->parent()->right_child(root->left_child());
                            root->left_child()->parent(root->parent());
                        }
                        Node<T> *to_delete = root;
                        root = root->left_child();
                        delete to_delete;
                    } else if (root->right_child() != NULL) {
                        if (root == this->root_) {
                            this->root_ = root;
                        } else if (root->parent()->left_child() == root) {
                            root->parent()->left_child(root->right_child());
                            root->right_child()->parent(root->parent());    
                        } else {
                            root->parent()->right_child(root->right_child());
                            root->right_child()->parent(root->parent());   
                        }
                        Node<T> *to_delete = root;
                        root = root->right_child();
                        delete to_delete;
                    } else {
                        Node<T> *to_delete = root;
                        if (this->root_ == root) {
                            this->root_ = NULL;
                        } else if (root->parent()->left_child() == root) {
                            root->parent()->left_child(NULL);
                        } else {
                            root->parent()->right_child(NULL);
                        }
                        delete to_delete;
                    }
                    if (single) {
                        break;
                    }
                }
            }
        }
    }

    Node<T> *
    mini_node(Node<T> *root) const
    {
        Node<T> *min = root;
        while (min != NULL && min->left_child() != NULL) {
            min = min->left_child();
        }
        return min;
    }
};

#endif /* _BINARY_SEARCH_TREE_H_ */
