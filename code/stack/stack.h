#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <cstdlib>

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

    void
    value(const T& value)
    { this->value_ = value; }

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
class Stack;

template <typename T>
std::ostream&
operator<<(std::ostream& os, const Stack<T>& stack);

template <typename T>
class Stack {
public:
    explicit Stack()
        :top_(NULL), size_(0)
    { }
    
    explicit Stack(const T& value)
        :top_(new Node<T>(value)), size_(1)
    { }

    explicit Stack(const T values[], const size_t& size);

    explicit Stack(const Stack<T>& stack);

    const Stack<T>&
    operator=(const Stack<T>& stack);

    ~Stack();

    friend std::ostream&
    operator<< <> (std::ostream& os, const Stack<T>& stack);
    
    const T&
    top() const
    { return this->top_->value(); }

    void
    push(const T& value)
    {
        Node<T> *node = new Node<T>(value, this->top_);
        this->top_ = node;
        ++this->size_;
    }

    const T
    pop()
    {
        Node<T> *to_delete = this->top_;
        this->top_ = this->top_->next();
        T top_value = to_delete->value();
        delete to_delete;
        --this->size_;
        return top_value;
    }

    const size_t&
    size() const
    { return this->size_; }
private:
    Node<T> *top_;
    size_t size_;
};

#endif /* _STACK_H_ */
