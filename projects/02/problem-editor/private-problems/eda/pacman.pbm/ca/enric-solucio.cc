
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int f, int c, const vector< vector<char> >& t, vector<
vector<bool> >& marked) {
  if (t[f][c] == 'B') return true;
  marked[f][c] = true;
  int DF[] = { 0, 0,-1, 1};
  int DC[] = {-1, 1, 0, 0};
  for (int k = 0; k < 4; ++k) {
    int ff = f + DF[k];
    int cc = c + DC[k];
    if (ff >= 0            and ff < t.size()    and
        cc >= 0            and cc < t[0].size() and
        not marked[ff][cc] and t[ff][cc] != 'X' and
        dfs(ff, cc, t, marked))
      return true;
  }
  return false;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector< vector<char> > t(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> t[i][j];

    int f0, c0;
    bool ok = true;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (t[i][j] == 'P') {
          f0 = i;
          c0 = j;
        }
        else if (t[i][j] == 'F') {
          for (int f = max(i-1, 0); f <= min(i+1, n-1); ++f)
            for (int c = max(j-1, 0); c <= min(j+1, m-1); ++c) {
              if      (t[f][c] == 'P') ok = false;
              else if (t[f][c] != 'F') t[f][c] = 'X';
            }
        }
    if (ok) {
      vector< vector<bool> > marked(n, vector<bool>(m, false));
      if (dfs(f0, c0, t, marked)) cout << "si" << endl;
      else                        cout << "no" << endl;
    }
    else cout << "no" << endl;
  }
}
