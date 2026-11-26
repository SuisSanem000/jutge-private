#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>
using namespace std;


atzar A(0);


const int N = 1e5;


typedef vector<int> VE;
typedef set<int> SE;


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


void store(int x, VE& Q, SE& S) {
  if (S.find(x) != S.end()) return;
  Q.push_back(x);
  S.insert(x);  
}


void test(int n, int j, int mx, int inc, int q) {
  SE S;
  VE V(n);
  VE Q;
  int a = A.uniforme(-mx, mx);
  int b;
  do b = A.uniforme(-mx, mx);
     while (b == a);
  if (a < b) swap(a, b);
  store(a, Q, S);
  store(a - 1, Q, S);
  store(a + 1, Q, S);
  store(b, Q, S);
  store(b - 1, Q, S);
  store(b + 1, Q, S);

  for (int i = 0; i <= j; ++i) {
    V[i] = a;
    a += 2*A.uniforme(0, inc);
  }
  for (int i = n - 1; i > j; --i) {
    V[i] = b;
    b -= 2*A.uniforme(0, inc);
  }

  store(V[j], Q, S);
  store(V[j] - 1, Q, S);
  store(V[j] + 1, Q, S);
  if (j - 1 >= 1) store(V[j-1], Q, S);
  if (j + 1 <= n - 2) store(V[j+1], Q, S);


  int e = V[j+1];
  int d = V[j];
  if (d - e + 1 < q) {
    e = -mx;
    d = mx;
  }
  while ((int)Q.size() < q) store(A.uniforme(e, d), Q, S);

  print(V, Q);
}


void test1() {
  VE Q;
  for (int r = 0; r < 1000; ++r)
    for (int x = 0; x <= 8; ++x) Q.push_back(x);

  int n = N;
  VE V(n);

  int j = n/2;
  V[0] = 5;
  for (int i = 1; i <= j; ++i) V[i] = 7;
  V[n-1] = 3;
  for (int i = n - 2; i > j; --i) V[i] = 1;
  print(V, Q);

  j = n/2 + 5;
  V[0] = 5;
  for (int i = 1; i <= j; ++i) V[i] = 7;
  V[n-1] = 3;
  for (int i = n - 2; i > j; --i) V[i] = 1;
  print(V, Q);

  j = n/2 - 7;
  V[0] = 5;
  for (int i = 1; i <= j; ++i) V[i] = 7;
  V[n-1] = 3;
  for (int i = n - 2; i > j; --i) V[i] = 1;
  print(V, Q);

  j = 23;
  V[0] = 5;
  for (int i = 1; i <= j; ++i) V[i] = 7;
  V[n-1] = 3;
  for (int i = n - 2; i > j; --i) V[i] = 1;
  print(V, Q);

  j = n - 42;
  V[0] = 5;
  for (int i = 1; i <= j; ++i) V[i] = 7;
  V[n-1] = 3;
  for (int i = n - 2; i > j; --i) V[i] = 1;
  print(V, Q);
}


void test3() {
  VE Q;
  int n = N - 1;
  VE V(n);

  int j = n/2 - 17;
  int a = 1000000;
  Q.push_back(a - 1);
  for (int i = 0; i <= j; ++i) {
    V[i] = a;
    Q.push_back(a);
    Q.push_back(a + 1);
    a += A.uniforme(2, 4);
  }
  int b = 500000;
  Q.push_back(b + 1);
  for (int i = n - 1; i > j; --i) {
    V[i] = b;
    Q.push_back(b);
    Q.push_back(b - 1);
    b -= A.uniforme(2, 4);
  }

  int m = Q.size();
  VE perm = A.permutacio(m);
  VE Q2;
  for (int i = 0; i < m; ++i) Q2.push_back(Q[perm[i]]);
  print(V, Q2);
}


int main() {
  test3();
}
