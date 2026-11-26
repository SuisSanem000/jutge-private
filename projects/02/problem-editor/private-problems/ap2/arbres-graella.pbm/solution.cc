#include <iostream>
#include <vector>
using namespace std;

// declare a matrix of characters
using Matrix = vector<vector<char>>;

// build a matrix given its size and default value
Matrix build_matrix(int rows, int columns, int value)
{
    return Matrix(rows, vector<char>(columns, value));
}

// declare the binary tree data structure
struct Node;

using Tree = Node*;

struct Node {
    char value;
    Tree left;
    Tree right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

// reads and returns a tree from its preorder
Tree read_tree()
{
    char c;
    cin >> c;
    if (c == '-') {
        return nullptr;
    } else {
        Tree l = read_tree();
        Tree r = read_tree();
        return new Node { c, l, r };
    }
}

// writes a matrix
void write(const Matrix& m)
{
    for (auto row : m) {
        for (auto element : row) {
            cout << element;
        }
        cout << endl;
    }
    cout << endl;
}

// returns the size (number of nodes) of a tree
int size(Tree t)
{
    if (t == nullptr) {
        return 0;
    } else {
        return 1 + size(t->left) + size(t->right);
    }
}

// returns the height of a tree
int height(Tree t)
{
    if (t == nullptr) {
        return 0;
    } else {
        return 1 + max(height(t->left), height(t->right));
    }
}

// helper function for the next function. y is the level of subtree t and
// x is the next position for its leftmost node. x is updated to
// its rightmost position minus one.
void tree_to_matrix_rec(Tree t, Matrix& m, int& x, int y)
{
    if (t != nullptr) {
        tree_to_matrix_rec(t->left, m, x, y + 1);
        m[y][x++] = t->value;
        tree_to_matrix_rec(t->right, m, x, y + 1);
    }
}

// place a tree into a matrix according to problem specifications
Matrix tree_to_matrix(Tree t)
{
    Matrix m = build_matrix(height(t), size(t), '.');
    int x = 0;
    tree_to_matrix_rec(t, m, x, 0);
    return m;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree t = read_tree();
        write(tree_to_matrix(t));
        delete t;
    }
}
