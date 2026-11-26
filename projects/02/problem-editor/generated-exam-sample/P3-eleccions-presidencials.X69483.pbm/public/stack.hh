#ifndef STACK_HH
#define STACK_HH

#include <vector>
#include "assert.hh"

namespace pro2 {

template <typename T>
class Stack {
    std::vector<T> elems_;

 public:
    // `vector` ja té un constructor per defecte!
    Stack() {}

    // Cridem al constructor de còpia de vector
    Stack(const std::vector<T>& elems) : elems_(elems) {}

    Stack(const Stack& other) : elems_(other.elems_) {}

    int size() const {
        return elems_.size();
    }

    bool empty() const {
        return elems_.empty();
    }

    void push(const T& x) {
        elems_.push_back(x);
    }

    const T& top() const {
        assert(elems_.size() > 0, "top: pila buida!");
        return elems_.back();
    }

    void pop() {
        assert(elems_.size() > 0, "pop: pila buida!");
        elems_.pop_back();
    }
};

}  // namespace pro2

#endif