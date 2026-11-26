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
  SP S;
  while ((int)S.size() < m) {
    int a = A.uniforme(0, n - 1);
    int b = A.uniforme(0, n - 1);
    if (a != b) {
      if (a > b) swap(a, b);
      S.insert(P(a, b));
    }
  }
  vector<P> V(S.begin(), S.end());

  VE perm = A.permutacio(n);
  VE perm2 = A.permutacio(m);
  cout << endl;
  cout << n << ' ' << m << endl;
  for (int i = 0; i < m; ++i) {
    int j = perm2[i];
    P z = V[j];
    int a = z.first;
    int b = z.second;
    cout << perm[a] << ' ' << perm[b] << endl;
  }
}


int main() {
  cout << "1 0" << endl;

  for (int r = 0; r < 200; ++r) {
    int n = A.uniforme(1, 10);
    test(n, A.uniforme(0, n*(n - 1)/2));
  }

  for (int r = 0; r < 200; ++r) {
    int n = A.uniforme(20, 100);
    test(n, A.uniforme(0, 10*n));
  }

  for (int r = 0; r < 200; ++r) {
    int n = A.uniforme(100, 1000);
    test(n, A.uniforme(0, 10*n));
  }
}
