#include "atzar.cc"
#include <iostream>
#include <vector>
using namespace std;


atzar A(8);


void test(int n, int m) {
  if (n > m or n < 1 or n*m > 23) {
    cerr << "pifia!!!" << endl;
    return;
  }

  cout << n << ' ' << m << endl;
}


void petits() {
  vector<int> N, M;
  for (int n = 1; n <= 4; ++n)
    for (int m = n; n*m <= 11; ++m) {
      N.push_back(n);
      M.push_back(m);
    }

  int t = N.size();
  vector<int> perm = A.permutacio(t);
  for (int i = 0; i < t; ++i) {
    int j = perm[i];
    test(N[j], M[j]);
  }
}


void grans() {
  vector<int> N, M;
  for (int n = 1; n <= 4; ++n)
    for (int m = max(n, 12/n); n*m <= 23; ++m) {
      N.push_back(n);
      M.push_back(m);
    }

  int t = N.size();
  vector<int> perm = A.permutacio(t);
  for (int i = 0; i < t; ++i) {
    int j = perm[i];
    test(N[j], M[j]);
  }
}


int main() {
  petits();

  grans();
}
