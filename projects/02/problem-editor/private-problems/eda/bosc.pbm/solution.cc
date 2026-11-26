#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


int n;
VVE G;
VE vist;


void marca(int x) {
  if (vist[x]) return;
  vist[x] = true;
  for (int i = 0; i < (int)G[x].size(); ++i) marca(G[x][i]);
}


int compos() {
  vist = VE(n, false);
  int res = 0;
  for (int x = 0; x < n; ++x)
    if (not vist[x]) {
      ++res;
      marca(x);
    }
  return res;
}


int main() {
  int m;
  while (cin >> n >> m) {
    G = VVE(n);
    for (int r = 0; r < m; ++r) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    int res = compos();
    if (res != n - m) cout << "no" << endl;
    else cout << res << endl;
  }
}
