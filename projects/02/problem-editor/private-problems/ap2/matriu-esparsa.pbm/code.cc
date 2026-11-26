#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

// Class to represent square sparse matrices
class SparseMatrix {

public:
    // Constructs an n×n sparse matrix full of zeros,
    // i.e., a vector of n empty lists.
    explicit SparseMatrix(int n)
    {
        ...
    }

    // Prints this matrix (just for testing, not efficient).
    void print() const
    {
        const int n = rows.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << get(i, j);
                if (j != n - 1) {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }

    // Sets the val of position i, j in this matrix to x.
    // You can assume that i and j are valid indices and that x ≠ 0.
    void set(int i, int j, int x)
    {
        const int n = rows.size();
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        assert(x != 0);

        ...
    }

    // Gets the val of position i, j in this matrix.
    // You can assume that i and j are valid indices.
    int get(int i, int j) const
    {
        const int n = rows.size();
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);

        ...
    }

    // Adds some matrix to this matrix.
    // You can assume that both have the same number of rows.
    void add(const SparseMatrix& other)
    {
        ...
    }

private:
    // You may define your own private methods here.
};

int main()
{
    map<string, SparseMatrix> matrices;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "create") {
            string name;
            int n;
            cin >> name >> n;
            matrices[name] = SparseMatrix(n);
        } else if (cmd == "set") {
            string name;
            int i, j, x;
            cin >> name >> i >> j >> x;
            matrices[name].set(i, j, x)
                :
        } else if (cmd == "get") {
            string name;
            int i, j;
            cin >> name >> i >> j;
            cout << matrices[name].get(i, j) << endl;
        } else if (cmd == "print") {
            string name;
            cin >> name;
            matrices[name].print();
        } else if (cmd == "add") {
            string name1, name2;
            cin >> name1 >> name2;
            matrices[name1].add(matrices[name2]);
        }
    }
}
