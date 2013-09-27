#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

template <typename T>
class Node {
public:
    explicit Node()
        :value_(), lch_(NULL), rch_(NULL)
    { }
    explicit Node(const T& value)
        :value_(value), lch_(NULL), rch_(NULL)
    { }
    explicit Node(const T& value, Node *lch)
        :value_(value), lch_(lch), rch_(NULL)
    { }
    explicit Node(const T& value, Node *lch, Node *rch)
        :value_(value), lch_(lch), rch_(rch)
    { }
    const Node&
    Node(const Node& node)
        :value_(node.value_), lch_(node.lch_), rch_(node.rch_)
    { }
    const Node&
    operator=(const Node& node);
    ~Node();
private:
    T value_;
    Node *lch_;
    Node *rch_;
};

template <typename T>
class BinaryTree {
public:
    explicit BinaryTree()
        :root_(NULL)
    { }
    explicit BinaryTree(Node *root)
        :root_(root)
    { }
    const BinaryTree&
    BinaryTree(const BinaryTree& tree)
        :root_(tree.root_)
    { }
    const BinaryTree&
    operator=(const BinaryTree& tree);
    ~BinaryTree();
private:
    Node *root_;
};

#endif /* _BINARY_TREE_H_ */
