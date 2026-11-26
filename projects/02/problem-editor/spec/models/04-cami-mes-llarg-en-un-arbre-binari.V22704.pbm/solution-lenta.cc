#include <algorithm>
#include <vector>
using namespace std;

#include "bintree.hh"
using namespace pro2;

int height(BinTree<int> t) {
    if (t.empty()) {
        return 0;
    } else {
        return 1 + max(height(t.left()), height(t.right()));
    }
}

void longest_leftmost_path__(BinTree<int> t, vector<int>& r) {
    if (t.empty()) {
        return;
    }
    r.push_back(t.value());
    if (height(t.left()) >= height(t.right())) {
        longest_leftmost_path__(t.left(), r);
    } else {
        longest_leftmost_path__(t.right(), r);
    }
}

vector<int> longest_leftmost_path(BinTree<int> t) {
    vector<int> r;
    longest_leftmost_path__(t, r);
    return r;
}
