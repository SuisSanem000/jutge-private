#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    while (cin >> k >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i)
            cin >> V[i];
        sort(V.begin(), V.end());
        int res = 0;
        int i = 0;
        while (i < n) {
            ++res;
            int x = V[i] + k;
            while (++i < n and V[i] <= x)
                ;
        }
        cout << res << endl;
    }
}
