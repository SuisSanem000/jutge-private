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


void escriu(int n, const vector<P>& V) {
  int m = V.size();
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


void test(int e, int d, int m) {
  int n = e + d;
  SP S;
  while ((int)S.size() < m) {
    int a = A.uniforme(0, e - 1);
    int b = A.uniforme(e, n - 1);
    S.insert(P(a, b));
  }
  vector<P> V(S.begin(), S.end());
  escriu(n, V);
}


int main() {
  cout << "2 1" << endl;
  cout << "0 1" << endl;

  for (int r = 0; r < 10; ++r) {
    int d = 9999;
    test(1, d, d);
  }

  for (int r = 0; r < 10; ++r) {
    int e = 9999;
    test(e, 1, e);
  }

  for (int r = 0; r < 3; ++r) {
    int e = 5000;
    test(e, e, 20*e);
  }
}
