#include "atzar.cc"
#include <iostream>
#include <vector>
using namespace std;


atzar A(0);


const int N = 1e4;


typedef vector<int> VE;


bool primer = true;


void print(const VE& V, const VE& Q) {
  int n = V.size();
  if (n < 2 or n > N or V[0] <= V[n-1]) {
    cerr << "pifia 1!!!" << endl;
    return;
  }

  int j = 0;
  while (++j < n and V[j] >= V[j-1]) ;
  if (j == n) {
    cerr << "pifia 2!!!" << endl;
    return;
  }

  while (++j < n and V[j] >= V[j-1]) ;
  if (j != n) {
    cerr << "pifia 3!!!" << endl;
    return;
  }

  int m = Q.size();
  if (primer) primer = false;
  else cout << endl;
  cout << n << ' ';
  for (int i = 0; i < n; ++i) cout << ' ' << V[i];
  cout << endl;
  cout << m << ' ';
  for (int i = 0; i < m; ++i) cout << ' ' << Q[i];
  cout << endl;
}


void test(int n, int j, int mx, int inc) {
  VE V(n);
  VE Q;
  int a = A.uniforme(-mx, mx);
  int b;
  do b = A.uniforme(-mx, mx);
     while (b == a);
  if (a < b) swap(a, b);
  Q.push_back(a);
  Q.push_back(a - 1);
  Q.push_back(a + 1);
  Q.push_back(b);
  Q.push_back(b - 1);
  Q.push_back(b + 1);

  for (int i = 0; i <= j; ++i) {
    V[i] = a;
    a += 2*A.uniforme(0, inc);
  }
  for (int i = n - 1; i > j; --i) {
    V[i] = b;
    b -= 2*A.uniforme(0, inc);
  }

  Q.push_back(V[j]);
  Q.push_back(V[j] - 1);
  Q.push_back(V[j] + 1);
  if (j - 1 >= 1) Q.push_back(V[j-1]);
  if (j + 1 <= n - 2) Q.push_back(V[j+1]);
  print(V, Q);
}


void extres() {
  VE V = { 114, 144, 161, 187, 190, 198, 200, 200, 200, 62 };
  VE Q = { 114, 144, 161, 187, 190, 198, 200, 62,
           112, 150, 170, 188, 192, 199, 201, 61, 63 };
  print(V, Q);

  V = { 172, 193, 195, 197, 199, 199, 201, 201, 201, 2, 88, 95, 99, 101 }; 
  Q = { 172, 193, 195, 197, 199, 201, 2, 88, 95, 99, 101,
        171, 180, 194, 196, 198, 200, 1, 3, 90, 96, 100, 102 };
  print(V, Q);

  V = { 183, 200, 200, 200, 200, 200, 54, 85 };
  Q = { 183, 200, 54, 85,
        180, 190, 210, 50, 60, 90 };
  print(V, Q);
}


int main() {
  extres();

  for (int inc = 0; inc <= 2; ++inc)
    for (int n = 2; n <= 10; ++n)
      for (int j = 0; j < n - 1; ++j) test(n, j, 100, inc);
}
