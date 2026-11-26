// proves
#undef NDEBUG

#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

// *******************************************************************************
// Class to represent square sparse matrices
// *******************************************************************************

class SparseMatrix {

    // Element in a row: a pair with the column index and the non-zero value.
    struct Elem {
        int col;
        int val;
    };

    // Sparse row of the matrix: list of non-zero values, with increasing column indices.
    using Row = list<Elem>;

    // Rows of the matrix
    vector<Row> rows;

public:
    // Constructs an n×n sparse matrix full of zeros,
    // i.e., a vector of n empty lists.
    explicit SparseMatrix(int n = 0)
    {
        rows = vector<list<Elem>>(n);
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

    // Gets the value at position (i, j) in this matrix.
    // You can assume that i and j are valid indices.
    int get(int i, int j) const
    {
        const int n = rows.size();
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);

        auto& l = rows[i];
        auto it = l.begin();
        while (it != l.end() and it->col < j) {
            ++it;
        }
        if (it == l.end() or it->col > j) {
            return 0;
        } else {
            return it->val;
        }
    }

    // Sets the value at position (i, j) in this matrix to x.
    // You can assume that i and j are valid indices and that x ≠ 0.
    void set(int i, int j, int x)
    {
        const int n = rows.size();
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        assert(x != 0);

        auto& l = rows[i];
        auto it = l.begin();
        while (it != l.end() and it->col < j) {
            ++it;
        }
        if (it == l.end() or it->col > j) {
            l.insert(it, { j, x });
        } else {
            it->val = x;
        }
    }

    // Adds some other matrix to this matrix.
    // You can assume that both matrices have the same number of rows
    // and that the two matrices are not the same object.
    void add(const SparseMatrix& other)
    {
        assert(rows.size() == other.rows.size());
        assert(this != &other);

        const int n = rows.size();
        for (int i = 0; i < n; ++i) {
            add(rows[i], other.rows[i]);
        }
    }

private:
    // You may define your own private methods here.

    void add(Row& l1, const Row& l2)
    {
        // this is a variations on the merging of two sorted lists

        auto it1 = l1.begin();
        auto it2 = l2.begin();

        while (it1 != l1.end() and it2 != l2.end()) {
            if (it1->col < it2->col) {
                ++it1;
            } else if (it1->col > it2->col) {
                l1.insert(it1, *it2);
                ++it2;
            } else {
                it1->val += it2->val;
                if (it1->val == 0) {
                    auto old = it1;
                    ++it1;
                    l1.erase(old);
                } else {
                    ++it1;
                }
                ++it2;
            }
        }

        while (it2 != l2.end()) {
            l1.push_back(*it2);
            ++it2;
        }
    }
};

int main()
{
    map<string, SparseMatrix> matrices;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "#") {
            cout << endl;
        } else if (cmd == "create") {
            string name;
            int n;
            cin >> name >> n;
            matrices[name] = SparseMatrix(n);
        } else if (cmd == "set") {
            string name;
            int i, j, x;
            cin >> name >> i >> j >> x;
            matrices[name].set(i, j, x);
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
