#ifndef QUEUE_HH
#define QUEUE_HH

#include <deque>
#include "assert.hh"

namespace pro2 {

template <typename T>
class Queue {
    std::deque<T> elems_;

 public:
    Queue() {}

    Queue(const std::deque<T>& elems) : elems_(elems) {}

    Queue(const Queue& other) : elems_(other.elems_) {}

    int size() const {
        return elems_.size();
    }

    bool empty() const {
        return elems_.empty();
    }

    void push(const T& x) {
        elems_.push_back(x);
    }

    const T& front() const {
        assert(elems_.size() > 0, "front: cua buida!");
        return elems_.front();
    }

    void pop() {
        assert(elems_.size() > 0, "pop: cua buida!");
        elems_.erase(elems_.begin());
    }
};

}  // namespace pro2

#endif