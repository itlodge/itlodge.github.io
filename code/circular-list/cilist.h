#ifndef _CILIST_H_
#define _CILIST_H_

#include <iostream>
#include <cassert>

template <typename T>
class Node {
public:
    explicit Node()
        :value_(), next_(NULL)
    { }
    explicit Node(const Node& n)
        :value_(n.value_), next_(n.next_)
    { }
    explicit Node(const T& value, Node<T> *next=NULL)
    {
        this->value_ = value;
        this->next_ = next;
    }
    const Node&
    operator=(const Node& n)
    {
        this->value_ = n.value_;
        this->next_ = n.next_;
        return *this;
    }
    ~Node() { }

    friend std::ostream&
    operator << (std::ostream& os, const Node& node)
    { return os << node.value_; }

    const T&
    value() const
    { return this->value_; }

    Node<T> *
    next() const
    { return this->next_; }

    // Set the 'next_' pointer to the pointer NEXT.
    void
    next(Node<T> *next)
    { this->next_ = next; }
private:
    Node<T> *next_;
    T value_;
};

template <typename T>
class CiLinkedList;

template <typename T>
std::ostream&
operator<<(std::ostream& os, const CiLinkedList<T>& list);

template <typename T>
class CiLinkedList {
public:
    explicit CiLinkedList()
        :head_(NULL), size_(0)
    { }

    explicit CiLinkedList(const T& value)
        :head_(new Node<T>(value)), size_(1)
    { this->head_->next(this->head_); }

    explicit CiLinkedList(const T values[], const size_t& size);

    explicit CiLinkedList(const CiLinkedList& list);

    const CiLinkedList&
    operator=(const CiLinkedList& list);

    ~CiLinkedList()
    { this->clean(); }

    const size_t&
    size() const
    { return this->size_; }

    const T&
    operator[](const size_t& index);
    
    friend std::ostream&
    operator<< <> (std::ostream& os, const CiLinkedList<T>& list);

    void
    rm_dup();
private:
    Node<T> *head_;
    size_t size_;

    void
    clean();
};

#endif /* _CILIST_H_ */


