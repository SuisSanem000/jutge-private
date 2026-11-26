#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> m;
int n;
int x;

void solve(int q, vector<int>& sp, int vsp, int rem, int& t) {
    if (vsp == x) ++t;
    else if (q < n) {
        for (int i = 0; i < 3; ++i) {
            sp[q] = 2 - i;
            vsp += m[q]*(2 - i);
            rem -= 2*m[q];
            if (vsp <= x and vsp + rem >= x) solve(q + 1, sp, vsp, rem, t);
            rem += 2*m[q];
            vsp -= m[q]*(2 - i);
            sp[q] = -1;
        }
    }
}
    

int main() {
    while (cin >> x >> n) {
        m = vector<int>(n);
        int rem = 0;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            rem += 2*m[i];
        }
        sort(m.begin(), m.end());
        vector<int> sp(n, -1);
        int t = 0;
        solve(0, sp, 0, rem, t);
        cout << t << endl;
    }
}
