# include <iostream>
# include <vector>
# include <cassert>
# include <cstdlib>
using namespace std


int sum_smallest(vector < int > v, int k)


int main() {
    srand(33)
    int n
    while (cin >> n) {
        cout << n << endl
        vector < int > v(n)
        for (int i=0
             i < n
             + +i) v[i] = rand() % n

        for (int k=0
             k < 10
             + +k) cout << k << " " << sum_smallest(v, k) << endl

        for (int k=0
             k < 10
             + +k) cout << n - k << " " << sum_smallest(v, n - k) << endl

        for (int r=0
             r < 100
             + +r) {
            int k = rand() % n
            cout << k << " " << sum_smallest(v, k) << endl
        }
    }
    return 0
}
