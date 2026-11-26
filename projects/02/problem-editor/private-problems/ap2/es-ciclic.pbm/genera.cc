#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>

using namespace std;


atzar A(0);


typedef vector<int> VE;
typedef pair<int, int> P;


P parell(int n) {
  int x = A.uniforme(0, n - 1);
  int y;
  do y = A.uniforme(0, n - 1);
     while (y == x);
  return P(x, y);
}


P parell2(int n) {
  int x = A.uniforme(0, n - 1);
  int y;
  do y = A.uniforme(0, n - 1);
     while (y == x);
  if (x > y) swap(x, y);
  return P(x, y);
}


P parell3(int n) {
  int x = A.uniforme(0, n - 1);
  int y;
  do y = A.uniforme(0, n - 1);
     while (y == x);
  if (x < y) swap(x, y);
  return P(x, y);
}


void f(int n, int m) {

  set<P> S;
  while ((int)S.size() < m) S.insert(parell(n));
  vector<P> V(S.begin(), S.end());

  VE perm1 = A.permutacio(n);
  VE perm2 = A.permutacio(m);
  cout << endl;
  cout << n << ' ' << m << endl;
  for (int j = 0; j < m; ++j) {
    int k = perm2[j];
    cout << V[k].first << "  " << V[k].second << endl;
  }
}


void g(int n) {

  int m = A.uniforme(0, min(5*n, n*(n - 1)/2));
  set<P> S;
  while ((int)S.size() < m) S.insert(parell2(n));
  vector<P> V(S.begin(), S.end());

  VE perm1 = A.permutacio(n);
  VE perm2 = A.permutacio(m);
  cout << endl;
  cout << n << ' ' << m << endl;
  for (int j = 0; j < m; ++j) {
    int k = perm2[j];
    cout << V[k].first << "  " << V[k].second << endl;
  }

  ++m;
  S.insert(parell3(n));
  V = vector<P>(S.begin(), S.end());

  perm1 = A.permutacio(n);
  perm2 = A.permutacio(m);
  cout << endl;
  cout << n << ' ' << m << endl;
  for (int j = 0; j < m; ++j) {
    int k = perm2[j];
    cout << V[k].first << "  " << V[k].second << endl;
  }
}


int main() {
  cout << "2 1" << endl;
  cout << "0  1" << endl;

  for (int n = 1; n <= 10; ++n)
    for (int m = 0; m <= min(5*n, n*(n - 1)); ++m) f(n, m);

  for (int r = 0; r < 200; ++r) g(50);
  for (int r = 0; r < 100; ++r) g(100);
  for (int r = 0; r < 20; ++r) g(500);
  for (int r = 0; r < 10; ++r) g(1000);
}
