#include <cassert>
#include <iostream>
using namespace std;

// define the coloring of the nodes
const char GREEN = 'G';
const char BLUE = 'B';

// define standard binary trees

struct Node;

using Tree = Node*;

struct Node {
    char color; // GREEN for green nodes, BLUE for blue nodes
    Tree left;
    Tree right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

// reads a tree according to the specification in the problem statement
Tree read()
{
    char c;
    cin >> c;
    if (c == '-') {
        return nullptr;
    } else {
        assert(c == GREEN or c == BLUE);
        Tree left = read();
        Tree right = read();
        return new Node { c, left, right };
    }
};

// tells whether a tree is blue-green and, if so, tells its blue height
bool blue_green(Tree t, int& blue_height)
{
    if (not t) {
        blue_height = 0;
        return true;
    }
    if (t->color == GREEN) {
        if (t->left and t->left->color == GREEN)
            return false;
        if (t->right and t->right->color == GREEN)
            return false;
    }
    int left_blue_height;
    if (not blue_green(t->left, left_blue_height))
        return false;
    int right_blue_height;
    if (not blue_green(t->right, right_blue_height))
        return false;
    if (left_blue_height != right_blue_height)
        return false;
    blue_height = left_blue_height + (t->color == BLUE);
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree t = read();
        int blue_height;
        if (blue_green(t, blue_height)) {
            cout << blue_height << endl;
        } else {
            cout << "no" << endl;
        }
        delete t;
    }
}
