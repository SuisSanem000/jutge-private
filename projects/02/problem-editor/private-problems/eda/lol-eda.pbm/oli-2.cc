#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > Matrix;

class Lol {
  int n; // rows
  int m; // columns
  Matrix T;
  int currentLols;
  int best;

  // PRE: (i,j) contains 'L'
  // POST: updates currentLols taking into account al LOLs that end in this position
  void updateCurrentLols(int i, int j){
    // Horizontal ending in (i,j)
    if (j - 2 >= 0 and T[i][j-2] == 'L' and T[i][j-1] == 'O') ++currentLols;

    // Vertical ending in (i,j)
    if (i - 2 >= 0 and T[i-2][j] == 'L' and T[i-1][j] == 'O') ++currentLols;

    // Diagonal1 ending in (i,j)
    if (i - 2 >= 0 and j - 2 >= 0 and
        T[i-2][j-2] == 'L' and T[i-1][j-1] == 'O') ++currentLols;

    // Diagonal2 ending in (i,j)
    if (j + 2 < m and i - 2 >= 0 and
        T[i-2][j+2] == 'L' and T[i-1][j+1] == 'O') ++currentLols;
  }

  void recursive(int cell){
    if (cell == n*m) {
      if (currentLols  > best) best  = currentLols;
    }
    else {
      int r = cell/m;
      int c = cell%m;
      int oldCurrent = currentLols;

      T[r][c] = 'L';
      updateCurrentLols(r,c);
      recursive(cell + 1);

      currentLols = oldCurrent;
      T[r][c] = 'O'; // No need tu update currentLols here
      recursive(cell + 1);

      // currentLols = oldCurrent; Not necessary!
    }
  }


public:
  Lol (int rows, int cols) {
    n = rows;
    m = cols;
    T = vector<vector<char> >(n,vector<char>(m));
    currentLols = 0;
    best = 0;
  }

  void solve() {
    recursive(0);
  }

  int number() {
    return best;
  }
};

int main(){
  int n, m;
  while (cin >> n >> m){
    Lol pb(n,m);
    pb.solve();
    cout << pb.number() << endl;
  }

}
