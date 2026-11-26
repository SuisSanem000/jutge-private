#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

bool bin_search(const vector<int>& a, int l, int r, int x) {
  if (l > r) return false;
  int m = (l+r)/2;
  if (a[m] < x) return bin_search(a, m+1, r,  x);
  if (a[m] > x) return bin_search(a,  l, m-1, x);
  return true;
}

bool search(const vector<int>& a, int l, int r, int x) {
  if (l+1 == r) return a[l] == x or a[r] == x;
  int m = (l+r)/2;
  if (a[m] >= a[l]) {
    if (a[l] <= x and x <= a[m]) {
      // return binary_search(a.begin()+l, a.begin()+m+1, x);
      return bin_search(a, l, m, x);
    }
    else return search(a, m, r, x);
  }
  else {
    assert(a[m] <= a[r]);
    if (a[m] <= x and x <= a[r]) {
      // return binary_search(a.begin()+m, a.begin()+r+1, x);
      return bin_search(a, m, r, x);
    }
    else return search(a, l, m, x);
  }
}

bool search(int x, const vector<int>& a) {
  return search(a, 0, a.size()-1, x);
}

int random(int l, int u) {
  return l + rand() % (u-l+1);
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
