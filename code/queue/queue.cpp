#include "queue.h"

template <typename T>
Queue<T>::Queue(const T values[], const size_t& size)
    :head_(NULL), tail_(NULL), size_(size)
{
    if (size > 0) {
        this->head_ = new Node<T>(values[0]);
        this->tail_ = this->head_;
        for (int i = 1; i < size; ++i) {
            Node<T> *node = new Node<T>(values[i]);
            this->tail_->next(node);
            this->tail_ = this->tail_->next();
        }
    }
}

template <typename T>
Queue<T>::Queue(const Queue<T>& queue)
    :head_(NULL), tail_(NULL), size_(queue.size_)
{
    if (this->size_ > 0) {
        Node<T> *p = queue.head_;
        this->head_ = new Node<T>(p->value());
        this->tail_ = this->head_;
        p = p->next();
        while (p != NULL) {
            Node<T> *node = new Node<T>(p->value());
            this->tail_->next(node);
            this->tail_ = this->tail_->next();
            p = p->next();
        }
    }
}

template <typename T>
const Queue<T>&
Queue<T>::operator=(const Queue<T>& queue)
{
    if (this->head_ == queue.head_) {
        return *this;
    }
    if (queue.size_ > 0) {
        Node<T> *pleft = this->head_;
        Node<T> *pright = queue.head_;
        while (pright != NULL) {
            if (pleft == NULL) {
                pleft = new Node<T>(pright->value());
            } else {
                pleft->value(pright->value());
            }
            pright = pright->next();
            this->tail_ = pleft;
            pleft = pleft->next();
        }
        while (pleft != NULL) {
            Node<T> *to_delete = pleft;
            pleft = pleft->next();
            delete to_delete;
        }
        this->tail_->next(NULL);
    } else {
        this->clean();
    }
    this->size_ = queue.size_;
    return *this;
}

template <typename T>
std::ostream&
operator<<(std::ostream& os, const Queue<T>& queue)
{
    std::string seperator = "";
    Node<T> *p = queue.head_;
    os << '[';
    while (p != NULL) {
        os << seperator << p->value();
        p = p->next();
        seperator = " | ";
    }
    os << ']';
    return os;
}

template <typename T>
void
Queue<T>::enQueue(const T& value)
{
    Node<T> *node = new Node<T>(value);
    if (this->size_ == 0) {
        this->head_ = node;
        this->tail_ = node;
    } else {
        this->tail_->next(node);
        this->tail_ = this->tail_->next();
    }
    ++this->size_;
}

template <typename T>
const T
Queue<T>::deQueue()
{
    if (this->size_ == 0) {
        std::cerr << "Cannot pop an empty queue\n";
        exit(1);
    } else {
        T value = this->head_->value();
        Node<T> *to_delete = this->head_;
        if (this->size_ == 1) {
            this->head_ = this->tail_ = NULL;
        } else {
            this->head_ = this->head_->next();
        }
        delete to_delete;
        --this->size_;
        return value;
    }
}
    
template <typename T>
void
Queue<T>::clean()
{
    Node<T> *p = this->head_;
    while (p != NULL) {
        Node<T> *to_delete = p;
        p = p->next();
        delete to_delete;
        --this->size_;
    }
    this->head_ = this->tail_ = NULL;
}


