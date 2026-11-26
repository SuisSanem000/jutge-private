#include <list>
using namespace std;

list<int>::iterator minim(list<int>::iterator begin, list<int>::iterator end) {
    auto min_it = begin;
    auto it = begin;
    ++it;
    for (; it != end; ++it) {
        if (*it < *min_it) {
            min_it = it;
        }
    }
    return min_it;
}

void ordenacio_seleccio(list<int>::iterator begin, list<int>::iterator end) {
    for (auto it = begin; it != end; ++it) {
        auto min_it = minim(it, end);
        if (min_it != it) {
            swap(*it, *min_it);
        }
    }
}
