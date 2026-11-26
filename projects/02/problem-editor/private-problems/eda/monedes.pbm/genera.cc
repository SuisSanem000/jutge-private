#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>
using namespace std;


atzar A(0);


typedef vector<int> VE;


void test(int x, int n) {
  if (n < 1 or n > 15 or x < 1 or x > 1e6 or n > x) {
    cerr << "pifia!" << endl;
    return;
  }

  set<int> S;
  while ((int)S.size() < n) S.insert(A.uniforme(1, x));
  VE V(S.begin(), S.end());
  VE perm = A.permutacio(n);
  cout << x << ' ' << n << ' ';
  for (int i = 0; i < n; ++i) cout << ' ' << V[perm[i]];
  cout << endl;
}


int main() {
  for (int x = 1; x <= 15; ++x)
    for (int n = 1; n <= x; ++n) test(x, n);

  for (int x = 100; x <= 5000; ++x) test(x, 15);

  for (int x = 1e6 - 5000; x <= 1000; ++x) test(x, 15);
}
