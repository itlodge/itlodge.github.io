#ifndef _BILIST_H_
#define _BILIST_H_

#include <iostream>
#include <cassert>

template <typename T>
class Node {
public:
    explicit Node()
        :value_(), prev_(NULL), next_(NULL)
    { }

    explicit Node(const T& value, Node *prev=NULL, Node *next=NULL)
        :value_(value), prev_(next), next_(next)
    { }

    explicit Node(const Node& node)
        :value_(node.value_), prev_(node.prev_), next_(node.next_)
    { }

    const Node&
    operator=(const Node& node)
    {
        this->value_ = node.value_;
        this->prev_ = node.prev_;
        this->next_ = node.next_;
    }

    ~Node() { }

    Node<T> *
    next() const
    { return this->next_; }

    const T&
    value() const
    { return this->value_; }

    void
    next(Node<T> *next)
    { this->next_ = next; }

    void
    prev(Node<T> *prev)
    { this->prev_ = prev; }

    friend std::ostream&
    operator<<(std::ostream& os, const Node<T>& node)
    { return os << node.value_; }
private:
    T value_;
    Node *prev_;
    Node *next_;
};

template <typename T>
class BiLinkedList;

template <typename T>
std::ostream&
operator<<(std::ostream&, const BiLinkedList<T>&);

template <typename T>
class BiLinkedList {
public:
    explicit BiLinkedList()
        :head_(NULL), size_(0)
    { }

    explicit BiLinkedList(const T& value)
        :head_(new Node<T>(value)), size_(1)
    { }

    explicit BiLinkedList(const T values[], size_t size);

    explicit BiLinkedList(const BiLinkedList& blist);
    
    const BiLinkedList&
    operator=(const BiLinkedList& blist);

    ~BiLinkedList()
    { this->clean(); }

    size_t
    size() const
    { return this->size_; }

    friend std::ostream&
    operator<< <> (std::ostream& os, const BiLinkedList<T>& list);

    const T&
    operator[](const size_t& index);

    void
    append(const T& value);

    void
    insert(size_t index, const T& value);

    void
    remove(size_t index);
private:
    Node<T> *head_;
    size_t size_;

    void
    clean();
};

#endif /* _BILIST_H_ */    
