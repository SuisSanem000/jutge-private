#include "atzar.cc"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

atzar A(0);

int main()
{
    for (int rep = 0; rep < 10; ++rep) {
        int n = 1e5;
        set<int> S;
        while ((int)S.size() < n)
            S.insert(A.uniforme(-1e9, 1e9));
        vector<int> V(S.begin(), S.end());
        vector<int> perm = A.permutacio(n);
        cout << 1000 << " " << n << "  ";
        for (int i = 0; i < n; ++i)
            cout << ' ' << V[perm[i]];
        cout << endl;
    }
}
