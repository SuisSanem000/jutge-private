/******************************************************************************

Estratègia utilitzada per l'algorisme:
    min_max_sum realitza una cerca binària per trobar
    el valor més petit de la màxima suma.

    has_max_sum va agafant tants elements consecutius com pot, d'esquerra a
    dreta. Quan no pot més incrementa el comptadors de parts. Si en algun moment
    hi ha massa parts, diu que no, altrament diu que sí.


Eficiència de l'algorisme: O(n log S)

Explicació de l'eficiència:
    És clar que has_max_sum triga O(n) i que min_max_sum fa
    O(log S) passos.

******************************************************************************/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// returns the sum of the elements of a vector
int sum(const vector<int>& v)
{
    int s = 0;
    for (int x : v) {
        s += x;
    }
    return s;
}

// returns whether the max-sum of a vector for m parts is ≤ x
bool has_max_sum(const vector<int>& v, int m, int x)
{
    int n = v.size();
    int c = 1; // current number of parts
    int s = 0; // sum of the current part
    for (int i = 0; i < n; ++i) {
        if (s + v[i] > x) {
            if (++c > m) {
                return false;
            }
            s = 0;
        }
        s += v[i];
        if (s > x) {
            return false;
        }
    }
    return true;
}

// returns the min-max-sum of a vector for m parts
int min_max_sum(const vector<int>& v, int m)
{
    int S = sum(v);
    int left = S / m; // si hi ha m parts, com a mínim hi ha d'haver una part que sumi sum(v)/m.
    int right = S;
    while (left != right) {
        assert(left < right);
        int mid = (left + right) / 2;
        if (has_max_sum(v, m, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// main program
int main()
{
    int m, n;
    while (cin >> m >> n) {
        vector<int> v(n);
        for (int& x : v) {
            cin >> x;
        }
        cout << min_max_sum(v, m) << endl;
    }
}
