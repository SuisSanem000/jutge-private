#ifndef HEAP_HH
#define HEAP_HH

#include <vector>
#include "assert.hh"

namespace pro2 {

template <typename T>
class Heap {
    std::vector<T> elems_;
    int size_;

    void resize_(int d);
    void flow_down_(int i);
    void flow_up_(int i);

 public:
    Heap() : elems_(1), size_(0) {}

    int size() const {
        return size_;
    }

    int capacity() const {
        return elems_.size() - 1;
    }

    bool empty() const {
        return size_ == 0;
    }

    const T& top() const {
        assert(!empty(), "top: referència a un element inexistent, heap buit");
        return elems_[1];
    }

    void push(const T& x) {
        resize_(1);
        elems_[size_] = x;
        flow_up_(size_);
    }

    void pop() {
        assert(!empty(), "pop: heap buit");
        elems_[1] = elems_[size_];
        resize_(-1);
        flow_down_(1);
    }
};

template <typename T>
void Heap<T>::resize_(int d) {
    assert(d == -1 || d == 1,
           "resize_: només es pot cridar per incrementar o decréixer mides d'1 en 1");

    int new_size = size_ + d;
    if (new_size > elems_.size() - 1) {
        elems_.resize(elems_.size() * 2);
    } else if (new_size < elems_.size() / 2) {
        elems_.resize(elems_.size() / 2);
    }
    size_ = new_size;
}

template <typename T>
void Heap<T>::flow_down_(int i) {
    int left = 2 * i, right = 2 * i + 1;
    int max = i;
    if (left <= size_ && elems_[left] > elems_[max]) {
        max = left;
    }
    if (right <= size_ && elems_[right] > elems_[max]) {
        max = right;
    }
    if (max != i) {
        std::swap(elems_[i], elems_[max]);
        flow_down_(max);
    }
}

template <typename T>
void Heap<T>::flow_up_(int i) {
    while (i > 1 && elems_[i] > elems_[i / 2]) {
        std::swap(elems_[i], elems_[i / 2]);
        i /= 2;
    }
}

}  // namespace pro2

#endif
