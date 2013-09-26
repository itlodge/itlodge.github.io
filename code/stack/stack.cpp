#include "stack.h"

template <typename T>
Stack<T>::Stack(const T values[], const size_t& size)
    :top_(NULL), size_(size)
{
    if (size > 0) {
        this->top_ = new Node<T>(values[0]);
        for (int i = 1; i < size; ++i) {
            Node<T> *node = new Node<T>(values[i], this->top_);
            this->top_ = node;
        }
    }
}

template <typename T>
Stack<T>::Stack(const Stack<T>& stack)
    :top_(NULL), size_(stack.size_)
{
    if (stack.size_ > 0) {
        Node<T> *p = stack.top_;
        this->top_ = new Node<T>(p->value());
        p = p->next();
        while (p != NULL) {
            Node<T> *node = new Node<T>(p->value(), this->top_);
            this->top_ = node;
            p = p->next();
        }
    }
}

template <typename T>
const Stack<T>&
Stack<T>::operator=(const Stack<T>& stack)
{
    Node<T> *pleft = this->top_;    
    Node<T> *pright = stack.top_;

    if (pleft == pright) {
        return *this;
    }
    if (pright != NULL) {
        if (pleft == NULL) {
            pleft = new Node<T>(pright->value());
            this->top_ = pleft;
        } else {
            pleft->value(pright->value());
        }
        pright = pright->next();
    }
    while (pright != NULL) {
        if (pleft->next() == NULL) {
            Node<T> *node = new Node<T>(pright->value());
            pleft->next(node);
        } else {
            Node<T> *p = pleft->next();
            p->value(pright->value());
        }
        pleft = pleft->next();
        pright = pright->next();
    }
    Node<T> *pprev = pleft;
    pleft = pleft->next();
    pprev->next(NULL);
    while (pleft != NULL) {
        Node<T> *to_delete = pleft;
        pleft = pleft->next();
        delete to_delete;
    }
    this->size_ = stack.size_;
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    Node<T> *p = this->top_;
    while (p != NULL) {
        Node<T> *to_delete = p;
        p = p->next();
        delete to_delete;
    }
    this->top_ = NULL;
}

template <typename T>
std::ostream&
operator<< (std::ostream& os, const Stack<T>& stack)
{
    Node<T> *p = stack.top_;
    std::string seperator = "";
    os << "[";
    while (p != NULL) {
        os << seperator << p->value();
        seperator = " | ";
        p = p->next();
    }
    os << "]";
    return os;
}
