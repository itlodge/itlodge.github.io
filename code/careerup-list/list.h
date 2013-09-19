#ifndef _CAREERUP_LIST_H_
#define _CAREERUP_LIST_H_

#include <iostream>

#undef NDEBUG
#include <cassert>

/* This class template is the Node of a singular linked list
 * value_: the value store in the node.
 * next_: the pointer that points to the next node. */
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
class LinkedList;

template <typename T>
std::ostream&
operator<<(std::ostream&, const LinkedList<T>&);

/* The singular linked list class template,
 * head_: a pointer pointing to the head of the list
 * size_: the length of the list */
template <typename T>
class LinkedList {
public:
    explicit LinkedList()
        :size_(0), head_(NULL)
    { }
    explicit LinkedList(const LinkedList& list)
        :size_(list.size_), head_(list.head_)
    { }

    // Create from a head node of value VALUE.
    explicit LinkedList(const T& value)
        :size_(1), head_(new Node<T>(value))
    { }

    // Create from an array VALUES of size SIZE.
    explicit LinkedList(const T values[], size_t size)
        :size_(size), head_(NULL)
    {
        if (size <= 0) {
            return;
        } else {
            this->head_ = new Node<T>(values[0]);
        }
        Node<T> *p = this->head_;
        for (size_t i = 1; i < size; ++i) {
            Node<T> *node = new Node<T>(values[i]);
            p->next(node);
            p = p->next();
        }
    }
    const LinkedList&
    operator=(const LinkedList& list);

    ~LinkedList()
    { this->clean(); }

    // Output a list in the form [a, b, c, ...].
    friend std::ostream&
    operator<< <> (std::ostream&, const LinkedList<T>&);

    // Add an element of value VALUE to the back of the list.
    void
    append(const T& value);

    // Return the value of the element in the position of INDEX.
    const T&
    operator[](size_t index) const
    { return this->get(index); }

    // Insert an element of value VALUE into the position INDEX.
    void
    insert(size_t index, const T& value);

    // Remove the element in the position INDEX.
    void
    remove(size_t index);

    size_t
    size() const
    { return this->size_; }

    void
    reverse();

    // Sort the list in the ascending order according to the type
    // of the value of the elements.
    void
    sort()
    { this->head_ = merge_sort(this->head_, this->size_); }

    // Remove duplicate elements.
    void
    rm_dup();

    // Return the nth to last element. i.e, 2th to last element of
    // list 1->2->3->4 is 2.
    const T&
    nth_to_last(size_t n) const
    { return this->get(this->size_ - n - 1); }
private:
    size_t size_;
    Node<T> *head_;

    Node<T> *
    merge_sort(Node<T> *head, size_t len);

    Node<T> *
    merge(Node<T> *lhs, Node<T> *rhs);

    void
    clean();

    const T&
    get(size_t n) const;
};

#endif /* _CAREERUP-LIST_H_ */
