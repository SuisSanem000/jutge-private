#include <iostream>
using namespace std;

// define standard binary search trees

struct Node;

using Tree = Node*;

struct Node {
    int x;
    Tree left; // all elems in left  are < x
    Tree right; // all elems in right are > x

    ~Node()
    {
        delete left;
        delete right;
    }
};

// reads a Tree according to the specification in the problem statement
Tree read()
{
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    } else {
        Tree left = read();
        Tree right = read();
        return new Node { x, left, right };
    }
};

Tree lowest_common_ancestor_bst(Tree t, int x, int y)
{
    if (t == nullptr)
        return nullptr;
    if (t->x > x and t->x > y)
        return lowest_common_ancestor_bst(t->left, x, y);
    if (t->x < x and t->x < y)
        return lowest_common_ancestor_bst(t->right, x, y);
    return t;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree t = read();
        int u, v;
        cin >> u >> v;
        while (u != -1) {
            Tree lca = lowest_common_ancestor_bst(t, u, v);
            cout << lca->x << endl;
            cin >> u >> v;
        }
        delete t;
        cout << endl;
    }
}
