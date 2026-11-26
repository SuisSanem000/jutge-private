#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> VC;
typedef vector<VC> VVC;


int n, m;
VVC M;
int mx;


void f(int i, int j, int q) {
  if (i == n) {
    mx = max(mx, q);
    return;
  }

  if (j == m) return f(i + 1, 0, q);

  M[i][j] = 'O';
  f(i, j + 1, q);

  M[i][j] = 'L';
  if (i >= 2 and M[i-2][j] == 'L' and M[i-1][j] == 'O') ++q;
  if (j >= 2 and M[i][j-2] == 'L' and M[i][j-1] == 'O') ++q;
  if (i >= 2 and j >= 2 and M[i-2][j-2] == 'L' and M[i-1][j-1] == 'O') ++q;
  if (i >= 2 and j <= m - 3 and M[i-2][j+2] == 'L' and M[i-1][j+1] == 'O') ++q;
  f(i, j + 1, q);
}


int main() {
  while (cin >> n >> m) {
    M = VVC(n, VC(m));
    mx = 0;
    f(0, 0, 0);
    cout << mx << endl;
  }
}
