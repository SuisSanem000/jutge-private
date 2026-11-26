#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int locate_cut(const vector<int>& v, int l, int u) {
  if (u - l == 1) { // subvector de 2 elementos
    return l;
  }
  // u - l > 1
  int m = (l + u) / 2;
  if (v[m] > v[m+1]) return m;
  if (v[0] <= v[m]) return locate_cut(v, m+1, u);
  // else v[0] > v[m]
  return locate_cut(v, l, m-1);
}

bool search(int x, const vector<int>& v) {
  int t = locate_cut(v, 0, v.size()-1);
  // v[t] > v[t+1]
  if (v[0] <= x)
    return binary_search(v.begin(), v.begin()+t+1, x); // busca x en el subvector v[0..t+1) 
  // else x < v[0]
  return binary_search(v.begin()+t+1, v.end(), x); // busca x en el subvector v[t+1..n) 
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}
