#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


atzar A(0);


const int N = 1000;
const int M = 1000;


typedef vector<int> VE;
typedef vector<VE> VVE;


bool primer = true;
VE pare;


void escriu(int n, const VVE& T) {
  int t = T.size();
  if (t < 1) {
    cerr << "pifia!!!" << endl;
    return;
  }

  VE perm3 = A.permutacio(n);
  int k = -1;
  while (perm3[++k]) ;
  swap(perm3[k], perm3[0]);

  bool zero = false;
  for (int i = 0; i < t; ++i) {
    set<int> S;
    VE V = T[i];
    int q = V.size();
    for (int j = 0; j < q; ++j) {
      int x = perm3[V[j]];
      if (x < 0 or x >= n or S.find(x) != S.end()) {
        cerr << "pifia!!!" << endl;
        return;
      }
      S.insert(x);
      if (x == 0) zero = true;
    }
  }
  if (not zero) {
    cerr << "pifia!!!" << endl;
    return;
  }

  VE perm = A.permutacio(t);
  if (primer) primer = false;
  else cout << endl;
  cout << n << ' ' << t << endl;
  for (int i = 0; i < t; ++i) {
    VE V = T[perm[i]];
    int q = V.size();
    VE perm2 = A.permutacio(q);
    cout << q << ' ';
    for (int j = 0; j < q; ++j) cout << ' ' << perm3[V[perm2[j]]];
    cout << endl;
  }
}


int repre(int x) {
  return (pare[x] == -1 ? x : pare[x] = repre(pare[x]));
}


VE article(int n, int q, bool erdos) {
  set<int> S;
  if (erdos) S.insert(0);
  while ((int)S.size() < q) S.insert(A.uniforme(0, n - 1));
  VE V(S.begin(), S.end());
  return V;
}


void test(int n, int mx, bool tots) {
  VVE T;
  pare = VE(n , -1);
  int grups = n;
  while (grups > 1) {
    T.push_back(article(n, A.uniforme(1, mx), T.empty()));

    for (int x : T.back())
      for (int y : T.back()) {
        int rx = repre(x);
        int ry = repre(y);
        if (rx != ry) {
          pare[ry] = rx;
          --grups;
        }
      }

    if (tots) escriu(n, T);
  }

  if (not tots) {
    escriu(n, T);
    T.pop_back();
    if (not T.empty()) escriu(n, T);
  }
}


void buti(int n, int mx) {
  VE perm = A.permutacio(n);
  int k = -1;
  while (perm[++k]) ;
  swap(perm[k], perm[0]);

  VVE T;
  int m = mx;
  VE V(m);
  for (int i = 0; i < m; ++i) V[i] = perm[i];
  T.push_back(V);
  int seg = m;
  while (seg < n) {
    m = A.uniforme(2, mx);
    int e = A.uniforme(1, m - 1);
    if (seg + m - 1 - e > n - 1) m = n + e - seg;

    V = VE(m);
    for (int i = 0; i < m; ++i) V[i] = perm[seg+i-e];
    T.push_back(V);
    seg += m - e;
  }

  escriu(n, T);
}


int main() {
  for (int n = 2; n < 10; ++n)
    for (int mx = 2; mx <= n; ++mx) test(n, mx, true);

  test(1000, 10, false);
  test(1000, 4, false);
  test(1000, 3, false);
  test(1000, 2, false);

  buti(100, 5);
  buti(100, 3);
  buti(100, 2);

  buti(10000, 2);
}
