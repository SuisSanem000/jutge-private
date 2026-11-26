#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> m;
int n;
int x;

void solve(int q, int vsp, int rem, int& t) {
    if (vsp == x) ++t;
    else if (q < n) {
        for (int i = 0; i < 3; ++i) {
            vsp += m[q]*(2 - i);
            rem -= 2*m[q];
            if (vsp <= x and vsp + rem >= x) solve(q + 1, vsp, rem, t);
            rem += 2*m[q];
            vsp -= m[q]*(2 - i);
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
        int t = 0;
        solve(0, 0, rem, t);
        cout << t << endl;
    }
}
