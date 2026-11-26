#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pt;

int movxF[]={-1,-1,-1,0,1,1,1,0};
int movyF[]={-1,0,1,1,1,0,-1,-1};
int movxP[]={-1,0,1,0};
int movyP[]={0,1,0,-1};
vector<vector<char> > m;

bool posible(int x, int y){
  queue<pt> q;
  bool enc=false;
  if (m[x][y]=='X') return false;
  q.push(pt(x,y)); 
  while (not q.empty() and not enc) {
    pt z=q.front(); q.pop();
    x=z.first; y=z.second; m[x][y]='X';
    for (int i=0; i<4 and not enc; ++i) {
      int a=x+movxP[i];
      int b=y+movyP[i];
      if (m[a][b]=='B') enc=true;
      else if (m[a][b]=='.') q.push(pt(a,b));
    }
  }
  return enc;
}

int main(){
  int nf, nc;
  while (cin >> nf >> nc) {
    m=vector<vector<char> > (nf, vector<char> (nc));
    vector<pt> fant;
    int bolet=0;
    int xini, yini;
    for (int i=0; i<nf; ++i) {
      for (int j=0; j<nc; ++j) {
        cin >> m[i][j];
        if (m[i][j]=='F') fant.push_back(pt(i,j));
        if (m[i][j]=='B') ++bolet;
        if (m[i][j]=='P') {
          xini=i; yini=j;
        }
      }
    }
    if (bolet==0) cout << "no" << endl;
    for (int i=0; i<int(fant.size()); ++i) {
      int x=fant[i].first;
      int y=fant[i].second;
      for (int k=0; k<8; ++k) {
        int a=x+movxF[k];
        int b=y+movyF[k]; 
        m[a][b]='X';
      }
    }
    if (posible(xini, yini)) cout << "si";
    else cout << "no";
    cout << endl;
  }
}
