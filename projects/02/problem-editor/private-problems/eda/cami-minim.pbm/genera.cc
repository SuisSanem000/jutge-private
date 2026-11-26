#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>
using namespace std;


atzar A(0);


typedef pair<int, int> P;
typedef set<P> SP;
typedef SP::iterator SI;
typedef vector<int> VE;


void test(int n, int m) {
  if (n < 2 or n > 10000 or m < 1 or m > 5*n) {
    cerr << "pifia!" << endl;
    return;
  }

  SP S;
  VE vist(n, false);
  int x = 0;
  vist[x] = true;
  while (not vist[n-1]) {
    if ((int)S.size() == m - 1) {
      S.insert(P(x, n - 1));
      vist[n-1] = true;
    }
    else {
      int y;
      do y = A.uniforme(0, n - 1);
         while (vist[y]);
      S.insert(P(x, y));
      vist[y] = true;
      x = y;
    }
  }

  while ((int)S.size() < m) {
    int x = A.uniforme(0, n - 1);
    int y = A.uniforme(0, n - 1);
    if (x != y) S.insert(P(x, y));
  }
  vector<P> V(S.begin(), S.end());

  VE perm = A.permutacio(m);
  cout << endl;
  cout << n << ' ' << m << endl;
  for (int i = 0; i < m; ++i) {
    int j = perm[i];
    cout << V[j].first << ' ' << V[j].second << endl;
  }
}


int main() {
  cout << "2 1" << endl;
  cout << "0 1" << endl;

  for (int r = 0; r < 200; ++r) {
    int n = A.uniforme(2, 10);
    test(n, A.uniforme(1, min(5*n, n*(n - 1))));
  }

  for (int r = 0; r < 200; ++r) {
    int n = A.uniforme(20, 100);
    test(n, A.uniforme(1, min(5*n, n*(n - 1))));
  }

  for (int r = 0; r < 200; ++r) {
    int n = A.uniforme(100, 1000);
    test(n, A.uniforme(1, min(5*n, n*(n - 1))));
  }

  test(10000, 1);
  test(10000, 10);
  test(10000, 100);
  test(10000, 1000);
  test(10000, 3000);
  test(10000, 5000);
  test(10000, 8000);
  test(10000, 10000);
  test(10000, 15000);
  test(10000, 20000);
  test(10000, 30000);
  test(10000, 40000);
  test(10000, 50000);
}
