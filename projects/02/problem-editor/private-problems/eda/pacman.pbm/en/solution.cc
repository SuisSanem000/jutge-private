#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> VC;
typedef vector<VC> VVC;


bool prof(int i, int j, VVC& M) {
  if (M[i][j] == 'B') return true;
  if (M[i][j] == 'X') return false;
  M[i][j] = 'X';
  return prof(i + 1, j, M) or prof(i - 1, j, M)
         or prof(i, j + 1, M) or prof(i, j - 1, M);
}


int main() {
  int f, c;
  while (cin >> f >> c) {
    VVC M(f, VC(c));
    int ip = -33, jp = -33;
    for (int i = 0; i < f; ++i)
      for (int j = 0; j < c; ++j) {
        cin >> M[i][j];
        if (M[i][j] == 'P') {
          ip = i;
          jp = j;
          M[i][j] = '.';
        }
      }

    VVC M2 = M;
    for (int i = 1; i < f - 1; ++i)
      for (int j = 1; j < c - 1; ++j)
        if (M[i][j] == 'F')
          for (int x = -1; x <= 1; ++x)
            for (int y = -1; y <= 1; ++y) M2[i + x][j + y] = 'X';
    cout << (prof(ip, jp, M2) ? "yes" : "no") << endl;
  }
}
