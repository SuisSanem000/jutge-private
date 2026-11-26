#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int xf[8] = {-1,-1,-1,0,0,1,1,1};
const int yf[8] = {-1,0,1,-1,1,-1,0,1};
const int x[4] = {0,0,1,-1};
const int y[4] = {1,-1,0,0};

bool cerca_bolet(vector<vector<char> >& M, pair<int,int> p) {
  queue<pair<int, int> > Q;
  if (M[p.first][p.second] == 'X') return false;
  M[p.first][p.second] = 'X'; Q.push(p); 
  while (not Q.empty()) {
    pair<int,int> q = Q.front(); Q.pop();
    for (int i = 0; i < 4; ++i) {
      int u = q.first + x[i];
      int v = q.second + y[i];
      if (M[u][v] == 'B') return true;
      if (M[u][v] != 'X') {
	M[u][v] = 'X';
	Q.push(make_pair(u,v));
      }
    }
  }
  return false;
}

int main() {
  int f, c; 
  while (cin >> f >> c) {
    vector<vector<char> > M(f, vector<char> (c));
    pair<int, int> p;
    queue<pair<int,int> > F;
    for (int i = 0; i < f; ++i) {
      for (int j = 0; j < c; ++j) {
	cin >> M[i][j];
	if (M[i][j] == 'P') {p.first = i; p.second = j;}
	if (M[i][j] == 'F') F.push(make_pair(i,j));
      }
    }
    while (not F.empty()) {
      int i = (F.front()).first;
      int j = (F.front()).second;
      F.pop();
      for (int k = 0; k < 8; ++k) M[i+xf[k]][j+yf[k]] = 'X';
    }
    if (cerca_bolet(M,p)) cout << "si" << endl;
    else cout << "no" << endl;
  }
}


