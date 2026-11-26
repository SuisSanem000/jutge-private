#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool search(const vector<int>& a, int l, int r, int x) {
  if (l+1 == r) return a[l] == x or a[r] == x;
  int m = (l+r)/2;
  if (a[m] >= a[l]) {
    if (a[l] <= x and x <= a[m]) {
      return binary_search(a.begin()+l, a.begin()+m+1, x);
    }
    else return search(a, m, r, x);
  }
  else {
    if (a[m] <= x and x <= a[r]) {
      return binary_search(a.begin()+m, a.begin()+r+1, x);
    }
    else return search(a, l, m, x);
  }
}


bool search(int x, const vector<int>& a) {
  return search(a, 0, a.size()-1, x);
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
