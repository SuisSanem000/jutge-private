#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using VE = vector<int>;
using VVE = vector<VE>;


int n;
VVE G;


void solu() {
  VE dist(n, -1);
  queue<int> Q;
  dist[0] = 0;
  Q.push(0);
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (dist[y] == -1) {
        dist[y] = dist[x] + 1;
        Q.push(y);
      }
  }

  for (int x = 0; x < n; ++x) {
    cout << x << " : ";
    if (dist[x] == -1) cout << "no" << endl;
    else cout << dist[x] << endl;
  }
  cout << string(10, '-') << endl;
}


int main() {
  int p;
  while (cin >> n >> p) {
    G = VVE(n);
    while (p--) {
      int q;
      cin >> q;
      VE V(q);
      for (int& x : V) cin >> x;
      for (int i = 0; i < q; ++i)
        for (int j = i + 1; j < q; ++j) {
          G[V[i]].push_back(V[j]);
          G[V[j]].push_back(V[i]);
        }
    }
    solu();
  }
}
