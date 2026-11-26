#include "atzar.cc"
#include <iostream>
#include <vector>
#include <set>
using namespace std;


atzar A(0);


#define X first
#define Y second


int inc_x[5] = { 0, 1, -1, 0, 0 };
int inc_y[5] = { 0, 0, 0, 1, -1 };


typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VE;
typedef vector<VE> VVE;
typedef pair<int, int> P;


P pos(int n, int m) {
  return P(A.uniforme(0, n - 1), A.uniforme(0, m - 1));
}


bool dins(int x, int y, int n, int m) {
  return x >= 0 and x < n and y >= 0 and y < m;
}


void test(int n, int m, int q) {
  VVC mapa(n, VC(m, '.'));
  VVE vist(n, VE(m, false));
  P ini = pos(n, m);
  P fi;
  do fi = pos(n, m);
     while (fi == ini);
  mapa[ini.X][ini.Y] = 'I';
  mapa[fi.X][fi.Y] = 'F';
  for (int k = 0; k < 5; ++k) {
    int x = ini.X + inc_x[k];
    int y = ini.Y + inc_y[k];
    if (dins(x, y, n, m)) vist[x][y] = true;
  }
  for (int k = 0; k < 5; ++k) {
    int x = fi.X + inc_x[k];
    int y = fi.Y + inc_y[k];
    if (dins(x, y, n, m)) vist[x][y] = true;
  }

  set<P> S;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (not vist[i][j]) S.insert(P(i, j));

  int mida = S.size();
  if (mida < q) {
    cerr << "pifia 1!!!" << endl;
    cerr << mida << ' ' << q << endl;
    cerr << n << ' ' << m << ' ' << q << endl;
    return;
  }

  vector<P> V(S.begin(), S.end());
  VE perm = A.permutacio(mida);
  for (int k = 0; k < q; ++k) {
    int z = perm[k];
    int i = V[z].X;
    int j = V[z].Y;
    mapa[i][j] = 'M';
  }

  cout << endl;
  cout << n << ' ' << m << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << mapa[i][j];
    cout << endl;
  }
}


int main() {
  cout << "1 2" << endl;
  cout << "IF" << endl;

  for (int n = 1; n < 10; ++n)
    for (int m = 1; m < 10; ++m)
      for (int q = 0; q <= min(n*m - 10, 5); ++q)
        for (int r = 0; r < 9; ++r) test(n, m, q);

  for (int r = 0; r < 1000; ++r) {
    int n = A.uniforme(1, 100);
    int m = A.uniforme(1, 100);
    if (n*m > 20) test(n, m, n*m/3);
  }
}
