#include <algorithm>
#include <vector>
using namespace std;

#include "bintree.hh"
using namespace pro2;

inline int value(const BinTree<int>& t) {
    return t.empty() ? 0 : t.value();
}

BinTree<int> tree_of_heights(BinTree<int> t) {
    if (t.empty()) {
        return BinTree<int>();
    }
    auto hl = tree_of_heights(t.left());
    auto hr = tree_of_heights(t.right());
    int h = max(value(hl), value(hr));
    return BinTree<int>(1 + h, hl, hr);
}

void longest_leftmost_path__(BinTree<int> t, BinTree<int> heights, vector<int>& r) {
    if (t.empty()) {
        return;
    }
    r.push_back(t.value());
    if (value(heights.left()) >= value(heights.right())) {
        longest_leftmost_path__(t.left(), heights.left(), r);
    } else {
        longest_leftmost_path__(t.right(), heights.right(), r);
    }
}

vector<int> longest_leftmost_path(BinTree<int> t) {
    vector<int> r;
    longest_leftmost_path__(t, tree_of_heights(t), r);
    return r;
}
