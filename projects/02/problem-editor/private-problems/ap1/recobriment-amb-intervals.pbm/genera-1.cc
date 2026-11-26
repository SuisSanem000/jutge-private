#include "atzar.cc"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

atzar A(0);

int main()
{
    for (int rep = 0; rep < 10000; ++rep) {
        int n = A.uniforme(0, 200);
        set<int> S;
        while ((int)S.size() < n)
            S.insert(A.uniforme(-10000, 10000));
        vector<int> V(S.begin(), S.end());
        vector<int> perm = A.permutacio(n);
        cout << 100 << " " << n << "   ";
        for (int i = 0; i < n; ++i)
            cout << ' ' << V[perm[i]];
        cout << endl;
    }
}
