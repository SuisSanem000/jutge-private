#include <iostream>
#include <vector>
using namespace std;

bool possible(int i, int j, const vector<int>& L)
{
    /*
    Indica si és possible posar el valor j a la posició i de L
    sabent que L[:i] és factible.
    */

    if (i == 0) {
        return true;
    }
    if (i % 2 == 0) {
        return j % 2 == L[i - 2] % 2;
    }
    if (i > 1) {
        return j > L[i - 2];
    }
    return true;
}

int compta(int i, int n, vector<int>& L, vector<bool>& u)
{
    /*
    Retorna el nombre de permutacions emparellades de longitud L
    estenent la permutació L[:i], sabent que aquesta és emparellada.
    Per a cada k ∈ {0 .. n-1}, u[k] indica si k ∈ L[:i].
    */

    if (i == n) {
        return 1;
    } else {
        int c = 0;
        for (int j = 0; j < n; ++j) {
            if (not u[j]) {
                if (possible(i, j, L)) {
                    L[i] = j;
                    u[j] = true;
                    c += compta(i + 1, n, L, u);
                    u[j] = false;
                }
            }
        }
        return c;
    }
}

int main()
{
    int n;
    while (cin >> n) {
        vector<int> L(n);
        vector<bool> u(n, false);
        cout << compta(0, n, L, u) << endl;
    }
}