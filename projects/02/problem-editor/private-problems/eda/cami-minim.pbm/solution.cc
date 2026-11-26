#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


int main() {
  int n, m;
  while (cin >> n >> m) {
    VVE G(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
    }
    for (int x = 0; x < n; ++x) sort(G[x].begin(), G[x].end());

    queue<int> Q;
    VE pare(n, -1);
    Q.push(0);
    pare[0] = -2;
    bool trobat = false;
    while (not trobat) {
      int x = Q.front(); Q.pop();
      for (int i = 0; i < (int)G[x].size(); ++i) {
        int y = G[x][i];
        if (pare[y] == -1) {
          Q.push(y);
          pare[y] = x;
          if (y == n - 1) trobat = true;
        }
      }
    }

    VE R;
    int x = n - 1;
    while (x != -2) {
      R.push_back(x);
      x = pare[x];
    }
    for (int i = R.size() - 1; i >= 0; --i) cout << R[i] << (i ? " " : "");
    cout << endl;
  }
}
