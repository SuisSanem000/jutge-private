/******************************************************************************

Estratègia utilitzada per l'algorisme:
    ...
    (màxim 5 línies)

Eficiència de l'algorisme: O(...)

Explicació de l'eficiència:
    ...
    (màxim 3 línies)

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
    for (int i = S / m; i <= S; ++i) {
        if (has_max_sum(v, m, i)) {
            return i;
        }
    }
    assert(false);
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
