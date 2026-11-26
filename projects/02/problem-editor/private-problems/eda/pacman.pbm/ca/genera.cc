#include "atzar.cc"
#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> VC;
typedef vector<VC> VVC;


atzar A(0);


void test(int f, int c, int b, double p1, double p2) {
  VVC V(f, VC(c, '.'));
  for (int i = 0; i < f; ++i) V[i][0] = V[i][c-1] = 'X';
  for (int j = 0; j < c; ++j) V[0][j] = V[f-1][j] = 'X';
  for (int i = 1; i < f - 1; ++i)
    for (int j = 1; j < c - 1; ++j)
      if (A.probabilitat(p1)) V[i][j] = 'X';
      else if (A.probabilitat(p2)) V[i][j] = 'F';
  while (b--) V[A.uniforme(1, f - 2)][A.uniforme(1, c - 2)] = 'B';
  V[A.uniforme(1, f - 2)][A.uniforme(1, c - 2)] = 'P';
  cout << f << ' ' << c << endl;
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) cout << V[i][j];
    cout << endl;
  }
}


int main() {
  test(3, 3, 0, 0, 0);
  test(3, 4, 10, 0, 0);
  test(4, 3, 10, 0, 0);
  test(3, 4, 0, 0, 0);
  test(4, 3, 0, 0, 0);
  for (int r = 0; r < 20; ++r) test(4, 4, 1, 0.8, 0);
  for (int r = 0; r < 10000; ++r) {
    int f = A.uniforme(3, 10);
    int c = A.uniforme(3, 10);
    double p1 = A.uniforme(0, 1, 3)/3;
    double p2 = A.uniforme(0, 1, 3)/10;
    test(f, c, A.uniforme(0, (f - 2)*(c - 2)/4), p1, p2);
  }
  for (int r = 0; r < 400; ++r) {
    int f = A.uniforme(3, 100);
    int c = A.uniforme(3, 100);
    double p1 = A.uniforme(0, 1, 3)/3;
    double p2 = A.uniforme(0, 1, 3)/10;
    test(f, c, A.uniforme(0, (f - 2)*(c - 2)/20), p1, p2);
  }
  for (double p1 = 0; p1 <= 0.5; p1 += 0.125)
    for (double p2 = 0; p2 <= 0.5; p2 += 0.125)
      test(100, 100, 100, p1, p2);
}
