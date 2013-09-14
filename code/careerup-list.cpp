#include "careerup-list.h"

template <typename T>
const LinkedList<T>&
LinkedList<T>::operator=(const LinkedList<T>& list)
{
    this->clean();
    this->size_ = list.size_;
    Node<T> *pright = list.head_;
    this->head_ = new Node<T>(pright->value());
    Node<T> *pleft = this->head_;
    pright = pright->next();
    while (pright != NULL) {
        pleft->next(new Node<T>(pright->value()));
        pleft = pleft->next();
        pright = pright->next();
    }
           
    return *this;
}

template <typename T>
std::ostream&
operator<<(std::ostream& os, const LinkedList<T>& list)
{
    Node<T> *p = list.head_;
    std::string separator = "";
    os << '[';
    while (p != NULL) {
        os << separator << p->value();
        separator = ", ";
        p = p->next();
    }
    os << ']';
    return os;
}

template <typename T>
void
LinkedList<T>::append(const T& value)
{
    Node<T> *node = new Node<T>(value);
    Node<T> *p = this->head_;
    if (p == NULL) {
        this->head_ = node;
    } else {
        while (p->next() != NULL) {
            p = p->next();
        }
        p->next(node);
    }

    ++this->size_;
}

template <typename T>
void
LinkedList<T>::insert(size_t index, const T& value)
{
    assert(index >= 0 && index <= this->size_);
    Node<T> *p = this->head_;
    if (index == 0) {
        Node<T> *node = new Node<T>(value, p);
        this->head_ = node;
    } else if (index == this->size_) {
        while (p->next() != NULL) {
            p = p->next();
        }
        Node<T> *node = new Node<T>(value);
        p->next(node);
    } else {
        int i = 1;
        while (i < index) {
            p = p->next();
            ++i;
        }
        Node<T> *node = new Node<T>(value, p->next());
        p->next(node);
    }
    ++this->size_;
}

template <typename T>
void
LinkedList<T>::remove(size_t index)
{
    if (index < 0 || index >= this->size_) {
        return;
    }
    Node<T> *p = this->head_;
    if (p == NULL) {
        return;
    }
    if (index == 0) {
        this->head_ = p->next();
        delete p;
    } else {
        int i = 1;
        while (i < index) {
            p = p->next();
            ++i;
        }
        Node<T> *to_delete = p->next();
        p->next(to_delete->next());
        delete to_delete;
    }
    --this->size_;
}

template <typename T>
void
LinkedList<T>::reverse()
{
    if (this->head_ == NULL) {
        return;
    }
    Node<T> *p = this->head_;
    Node<T> *prev = p;
    Node<T> *next = p->next();
    prev->next(NULL);
    while (next->next() != NULL) {
        p = next;
        next = p->next();
        p->next(prev);
        prev = p;
    }
    p = next;
    p->next(prev);
    this->head_ = p;
}

template <typename T>
Node<T> *
LinkedList<T>::merge_sort(Node<T> *head, size_t len)
{
    if (len < 1) {
        return head;
    } else if (len < 2) {
        head->next(NULL);
        return head;
    } else {
        int i = 0;
        Node<T> *p = head;
        while (i < len / 2) {
            p = p->next();
            ++i;
        }
        head = merge_sort(head, len / 2);
        p = merge_sort(p, len - len / 2);
        return merge(head, p);
    }
}

template <typename T>
Node<T> *
LinkedList<T>::merge(Node<T> *lhs, Node<T> *rhs)
{
    Node<T> *pright = rhs;
    Node<T> *pleft = lhs;
    Node<T> *pleft_prev = lhs;
    if (rhs->value() < lhs->value()) {
        pright = rhs->next();
        rhs->next(lhs);
        lhs = rhs;
        pleft_prev = lhs;
        pleft = lhs->next();
    }
    while (pleft != NULL && pright != NULL) {
        if (pright->value() < pleft->value()) {
            pleft_prev->next(pright);
            pright = pright->next();
            pleft_prev = pleft_prev->next();
            pleft_prev->next(pleft);
            pleft = pleft_prev->next();
        } else {
            pleft_prev = pleft;
            pleft = pleft->next();
        }
    }
    while (pright != NULL) {
        pleft_prev->next(pright);
        pleft_prev = pleft_prev->next();
        pright = pright->next();
    }
    return lhs;
}

template <typename T>
void
LinkedList<T>::clean()
{
    Node<T> *p = this->head_;
    while (p != NULL) {
        Node<T> *to_delete = p;
        p = p->next();
        delete to_delete;
    }
}

template <typename T>
const T&
LinkedList<T>::get(size_t index) const
{
    assert(index >= 0 && index < this->size_);
    int i = 0;
    Node<T> *p = this->head_;
    while (i < index) {
        p = p->next();
        ++i;
    }
    return p->value();
}

template <typename T>
void
LinkedList<T>::rm_dup()
{
    if (this->head_ == NULL || this->size_ <= 1) {
        return;
    }
    for (Node<T> *pleft = this->head_;
         pleft != NULL && pleft->next() != NULL;
         pleft = pleft->next()) {
        for (Node<T> *pright = pleft->next(), *pprev = pleft;
             pright != NULL;) {
            if (pleft->value() == pright->value()) {
                pprev->next(pright->next());
                delete pright;
                --this->size_;
                pright = pprev->next();
            } else {
                pprev = pright;
                pright = pright->next();
            }
        }
    }
}
