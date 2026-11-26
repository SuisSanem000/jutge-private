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

// returns whether v has a max-sum in m parts ≤ x
bool has_max_sum(const vector<int>& v, int m, int x)
{
    ...
}

// returns the min-max-sum of a vector for m parts
int min_max_sum(const vector<int>& v, int m)
{
    ...
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
