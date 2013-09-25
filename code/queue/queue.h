#ifndef _QUEUE_H_
#define _QUEUE_H_

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
class Queue;

template <typename T>
std::ostream&
operator<<(std::ostream& os, const Queue<T>& queue);

template <typename T>
class Queue {
public:
    explicit Queue()
        :head_(NULL), tail_(NULL), size_(0)
    { }

    explicit Queue(const T& value)
        :head_(new Node<T>(value)), tail_(head_), size_(1)
    { }

    explicit Queue(const T values[], const size_t& size);

    explicit Queue(const Queue<T>& queue);

    const Queue<T>&
    operator=(const Queue<T>& queue);

    ~Queue()
    { this->clean(); }

    friend std::ostream&
    operator<< <> (std::ostream& os, const Queue<T>& queue);

    const T&
    head() const
    {
        if (this->size_ == 0) {
            std::cerr << "The queue is empty!\n";
            exit(1);
        }
        return this->head_->value();
    }   

    size_t
    size() const
    { return this->size_; }
    
    void
    enQueue(const T& value);

    const T
    deQueue();
private:
    Node<T> *head_;
    Node<T> *tail_;
    size_t size_;

    void
    clean();
};

#endif /* _QUEUE_H_ */
