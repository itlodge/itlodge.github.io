#include "cilist.h"

template <typename T>
CiLinkedList<T>::CiLinkedList(const T values[], const size_t& size)
    :head_(NULL), size_(size)
{
    if (size == 1) {
        this->head_ = new Node<T>(values[0]);
        this->head_->next(this->head_);
    } else if (size > 1) {
        this->head_ = new Node<T>(values[0]);
        Node<T> *p = this->head_;
        for (int i = 1; i < size; ++i) {
            Node<T> *node = new Node<T>(values[i]);
            p->next(node);
            p = p->next();
        }
        p->next(this->head_);
    }
}

template <typename T>
CiLinkedList<T>::CiLinkedList(const CiLinkedList& list)
    :head_(NULL), size_(list.size_)
{
    Node<T> *pright = list.head_;
    if (pright != NULL) {
        this->head_ = new Node<T>(pright->value());
        Node<T> *pleft = this->head_;
        while (pright->next() != list.head_) {
            pright = pright->next();
            Node<T> *node = new Node<T>(pright->value());
            pleft->next(node);
            pleft = pleft->next();
        }
        pleft->next(this->head_);
    }
}

template <typename T>
const CiLinkedList<T>&
CiLinkedList<T>::operator=(const CiLinkedList<T>& list)
{
    if (this->head_ == list.head_) {
        return *this;
    }
    this->clean();
    this->size_ = list.size_;
    if (list.head_ != NULL) {
        Node<T> *p = list.head_;
        this->head_ = new Node<T>(p->value());
        Node<T> *thisp = this->head_;
        p = p->next();
        while (p != list.head_) {
            Node<T> *node = new Node<T>(p->value());
            thisp->next(node);
            thisp = thisp->next();
            p = p->next();
        }
        thisp->next(this->head_);
    }
    return *this;
}

template <typename T>
const T&
CiLinkedList<T>::operator[](const size_t& index)
{
    assert(index >= 0 && index <= this->size_);
    size_t i = 0;
    Node<T> *p = this->head_;
    while (i < index) {
        p = p->next();
        ++i;
    }
    return p->value();
}

template <typename T>
std::ostream&
operator<<(std::ostream& os, const CiLinkedList<T>& list)
{
    Node<T> *p = list.head_;
    std::string seperator = "";
    os << '[';
    if (p != NULL) {
        while (p->next() != list.head_) {
            os << seperator << p->value();
            p = p->next();
            seperator = ", ";
        }
        os << seperator << p->value();
    }
    os << ']';
    return os;
}

template <typename T>
void
CiLinkedList<T>::rm_dup()
{
    if (this->size_ <= 1) {
        return;
    }
    Node<T> *p = this->head_;
    while (p->next() != this->head_) {
        Node<T> *pprev = p;
        Node<T> *pnext = p->next();
        while (pnext != this->head_) {
            if (p->value() == pnext->value()) {
                pprev->next(pnext->next());
                delete pnext;
                --this->size_;
                pnext = pprev->next();
            } else {
                pprev = pnext;
                pnext = pprev->next();
            }
        }
        p = p->next();
    }
}

template <typename T>
void
CiLinkedList<T>::clean()
{
    Node<T> *p = this->head_;
    while (p != NULL) {
        if (this->size_ == 1) {
            delete p;
            --this->size_;
            break;
        } else if (p == this->head_) {
            Node<T> *temp = p;
            p = p->next();
            temp->next(NULL);
        } else {
            Node<T> *to_delete = p;
            p = p->next();
            delete to_delete;
            --this->size_;
        }
    }
    this->head_ = NULL;
}


    
