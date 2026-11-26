#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>
using namespace std;


atzar A(0);


const int N = 1e4;


typedef pair<int, int> P;
typedef vector<int> VE;
typedef vector<P> VP;
typedef set<P> SP;


VE pare;


P aresta(int n) {
  int x = A.uniforme(0, n - 1);
  int y;
  do y = A.uniforme(0, n - 1);
     while (y == x);
  if (y > x) swap(x, y);
  return P(x, y);
}


int repre(int x) {
  return (pare[x] == -1 ? x : pare[x] = repre(pare[x]));
}


void escriu(int n, SP& S) {
  VP V(S.begin(), S.end());
  int m = V.size();
  if (m > n - 1) return;

  VE perm = A.permutacio(m);
  cout << n << ' ' << m;
  for (int i = 0; i < m; ++i) {
    int j = perm[i];
    int x = V[j].first;
    int y = V[j].second;
    if (A.uniforme(0, 1)) swap(x, y);
    cout << "  " << x << " " << y;
  }
  cout << endl;
}


void test(int n, int m) {
  if (n < 1 or n > N or m < 0 or m > n - 1) {
    cerr << "pifia!" << endl;
    return;
  }

  pare = VE(n, -1);
  SP S;
  while ((int)S.size() < m) {
    P a = aresta(n);
    int x = a.first;
    int y = a.second;
    int rx = repre(x);
    int ry = repre(y);
    if (rx != ry) {
      S.insert(a);
      pare[ry] = rx;
    }
  }
  escriu(n, S);

  for (int r = 0; (int)S.size() < n - 1 and r < 5; ++r) {
    S.insert(aresta(n));
    escriu(n, S);
  }
}


int main() {
  for (int n = 1; n < 50; ++n)
    for (int m = 0; m < n; ++m) test(n, m);

  for (int n = 100; n < N/10; n += 100) test(n, A.uniforme(0, n - 6));

  for (int n = 1000; n < N; n += 1000) test(n, A.uniforme(0, n - 6));

  test(N, N/4);
  test(N, N/2);
  test(N, 3*N/4);
  test(N, N - 6);
}
