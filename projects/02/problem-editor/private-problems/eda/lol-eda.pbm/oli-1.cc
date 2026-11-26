#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > Matrix;

class Lol {
  int n; // rows
  int m; // columns
  Matrix T;
  int best;

  // Assuming (i,j) = 'O', is it part of an horizontal LOL?
  bool horizontalLol(int i, int j) {
    return j - 1 >= 0 and T[i][j-1] == 'L' and
      j + 1 < m and  T[i][j+1] == 'L';
  }

  // Assuming (i,j) = 'O', is it part of a vertical LOL?
  bool verticalLol(int i, int j) {
    return i - 1 >= 0 and T[i-1][j] == 'L' and
      i + 1 < n and  T[i+1][j] == 'L';
  }

  // Assuming (i,j) = 'O', is it part of a diagonal1 LOL?
  bool diagonal1Lol(int i, int j) {
    return i - 1 >= 0 and j - 1 >= 0 and T[i-1][j-1] == 'L' and
      i + 1 < n and j + 1 < m and  T[i+1][j+1] == 'L';
  }

  // Assuming (i,j) = 'O', is it part of a diagonal2 LOL?
  bool diagonal2Lol(int i, int j) {
    return i + 1 < n and j - 1 >= 0 and T[i+1][j-1] == 'L' and
      i - 1 >= 0 and j + 1 < m and  T[i-1][j+1] == 'L';
  }

  // Given filled T, counts the number of LOLs
  int numberLols(){
    int number = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (T[i][j] == 'O') {
          if (horizontalLol(i,j)) ++number;
          if (verticalLol(i,j)) ++number;
          if (diagonal1Lol(i,j)) ++number;
          if (diagonal2Lol(i,j)) ++number;
        }
      }
    return number;
  }

  void recursive(int cell){
    if (cell == n*m) {
      int x = numberLols();
      if (x  > best) best  = x;
    }
    else {
      int r = cell/m;
      int c = cell%m;

      T[r][c] = 'L';
      recursive(cell + 1);

      T[r][c] = 'O';
      recursive(cell + 1);
    }
  }


public:
  Lol (int rows, int cols) {
    n = rows;
    m = cols;
    T = vector<vector<char> >(n,vector<char>(m));
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
