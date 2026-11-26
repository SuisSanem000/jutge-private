#include <iostream>
#include <vector>
#include <set>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


int main() {
  int n, m;
  while (cin >> n >> m) {
    VVE G(n);
    VE grau(n, 0);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      ++grau[y];
    }

    set<int> S;
    for (int x = 0; x < n; ++x)
      if (grau[x] == 0) S.insert(x);

    for (int j = 0; j < n; ++j) {
      if (S.empty()) cerr << "PIFIA!!!" << endl;

      int x = *S.begin();
      S.erase(x);
      cout << (j ? " " : "") << x;
      for (int i = 0; i < (int)G[x].size(); ++i) {
        int y = G[x][i];
        if (--grau[y] == 0) S.insert(y);
      }
    }
    cout << endl;
  }
}
