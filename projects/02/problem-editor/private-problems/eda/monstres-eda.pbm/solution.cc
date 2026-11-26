#include <iostream>
#include <vector>
using namespace std;


int inc_x[4] = { 1, -1, 0, 0 };
int inc_y[4] = { 0, 0, 1, -1 };


typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VE;
typedef vector<VE> VVE;


int n, m;
VVC mapa;
VVE vist;


bool dins(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < m;
}


bool busca(int x, int y) {
  if (not dins(x, y) or vist[x][y]) return false;
  vist[x][y] = true;
  if (mapa[x][y] == 'F') return true;
  for (int k = 0; k < 4; ++k)
    if (busca(x + inc_x[k], y + inc_y[k])) return true;
  return false;
}


int main() {
  while (cin >> n >> m) {
    mapa = VVC(n, VC(m));
    int xi=0, yi=0;		//jpetit: poso =0 pq sino dona warnign
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> mapa[i][j];
        if (mapa[i][j] == 'I') {
          xi = i;
          yi = j;
        }
      }

    vist = VVE(n, VE(m, false));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        char c = mapa[i][j];
        if (c == 'M') {
          for (int k = 0; k < 4; ++k) {
            int x = i + inc_x[k];
            int y = j + inc_y[k];
            if (dins(x, y)) {
              if (mapa[x][y] == 'I' or mapa[x][y] == 'F') cerr << "PIFIA!!!" << endl;
              vist[x][y] = true;
            }
          }
        }
      }
    cout << (busca(xi, yi) ? "SI" : "NO") << endl;
  }
}
