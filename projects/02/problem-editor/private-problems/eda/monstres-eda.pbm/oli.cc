#include <iostream>
#include <vector>
#include <stack>

using namespace std;


typedef vector<vector<char> > Matrix;


bool valid (const Matrix& T, int i, int j) {
  return ( i >= 0 and i < T.size() and j >= 0 and j < T[0].size() and // within limits
          (not(i - 1 >= 0) or  T[i-1][j] != 'M') and // no threat from above
          (not(i + 1 < T.size()) or T[i+1][j] != 'M') and // no threat from below
          (not(j - 1 >= 0) or T[i][j-1] != 'M') and // no threat from the left
          (not(j + 1 < T[0].size()) or T[i][j+1] != 'M')
         ); // no threat from the right
}

bool reachable(const Matrix& T, pair<int,int>& orig, pair<int,int>& dest) {
  vector<vector<bool> > visited(T.size(),vector<bool>(T[0].size(),false));

  stack<pair<int,int> > S;
  S.push(orig);
  while (not S.empty()) {
    pair<int,int> v = S.top();
    S.pop();
    if (not visited[v.first][v.second]){
      if (v == dest) return true;
      visited[v.first][v.second] = true;

      // Visit successors
      if (valid(T, v.first, v.second - 1)) S.push({v.first,v.second - 1});
// left
      if (valid(T, v.first, v.second + 1)) S.push({v.first,v.second + 1});
// right
      if (valid(T, v.first - 1, v.second)) S.push({v.first - 1, v.second}); // up
      if (valid(T, v.first + 1, v.second)) S.push({v.first + 1, v.second}); // down

    }
  }

  return false;
}

int main() {
  int n, m;
  while (cin >> n >> m){
    // Read matrix
    Matrix T(n,vector<char>(m));
    pair<int,int> origin;
    pair<int,int> destination;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        if (c == 'I') origin = {i,j};
        else if (c == 'F') destination = {i,j};
        T[i][j] = c;
      }

    if (reachable(T,origin,destination)) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
}
