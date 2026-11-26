#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

  int f, c;

bool mob(const vector<vector<char> >& m, int i, int j) {
  if (m[i][j] == 'X') return false;
  for (int di=-1; di<=1; ++di) {
    for (int dj=-1; dj<=1; ++dj) {
      if (i+di>=0 and i+di<f and j+dj>=0 and j+dj<c) {
        if (m[i+di][j+dj] == 'F') return false;      
  } } }
  return true;
}


void va(queue<int>& q, vector<vector<char> >& m, vector<vector<char> >& v, int i, int j) {
  if (i < f and not v[i][j] and mob(m, i, j)) {
    v[i][j] = true;
    q.push(i); q.push(j);
  }
}

int main () {
  while (cin >> f >> c) {
    vector<vector<char> > m(f, vector<char>(c));
    vector<vector<char> > v(f, vector<char>(c, 0));
    int si, sj;
    queue<int> q;
    for (int i=0; i<f; ++i) {
      for (int j=0; j<c; ++j) {
        cin >> m[i][j];
        if (m[i][j] == 'P') {
          si = i; sj = j;
    } } }

    if (mob(m, si, sj)) {
      q.push(si); q.push(sj);
      v[si][sj] = true;
    }

    while (not q.empty()) {
      int i = q.front(); q.pop();
      int j = q.front(); q.pop();
      va(q, m, v, i+1, j);
      va(q, m, v, i-1, j);
      va(q, m, v, i, j+1);
      va(q, m, v, i, j-1);
    }

    bool fnd = false;
    for (int i=0; i<f; ++i) {
      for (int j=0; j<c; ++j) {
        if (v[i][j] and m[i][j]=='B') fnd = true;
    } }
    if (fnd) cout << "si" << endl; else cout << "no" << endl;
} }
