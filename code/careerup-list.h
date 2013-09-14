#ifndef _CAREERUP_LIST_H_
#define _CAREERUP_LIST_H_

#include <iostream>

#undef NDEBUG
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

template <typename T>
class LinkedList {
public:
    explicit LinkedList()
        :size_(0), head_(NULL)
    { }
    explicit LinkedList(const LinkedList& list)
        :size_(list.size_), head_(list.head_)
    { }
    explicit LinkedList(const T& value)
        :size_(1), head_(new Node<T>(value))
    { }
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

    friend std::ostream&
    operator<< <> (std::ostream&, const LinkedList<T>&);
    
    void
    append(const T& value);

    const T&
    operator[](size_t index) const
    { return this->get(index); }

    void
    insert(size_t index, const T& value);

    void
    remove(size_t index);

    size_t
    size() const
    { return this->size_; }

    void
    reverse();

    void
    sort()
    { this->head_ = merge_sort(this->head_, this->size_); }

    void
    rm_dup();

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
