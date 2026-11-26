#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

bool search(const vector<int>& a, int l, int r, int x) {
  while (l+1 < r) {
    int m = (l+r)/2;
    if (a[m] >= a[l]) {
      if (a[l] <= x and x <= a[m]) return binary_search(a.begin()+l, a.begin()+m+1, x);
      else l = m;
    }
    else {
      if (a[m] <= x and x <= a[r]) return binary_search(a.begin()+m, a.begin()+r+1, x);
      else r = m;
    }
  }
  return a[l] == x or a[r] == x;
}

bool search(int x, const vector<int>& a) {
  return search(a, 0, a.size()-1, x);
}

int random(int l, int u) {
  return l + rand() % (u-l+1);
}

int main() {
  srand(time(NULL));

  vector<int> a;
  int n, p;

  n = random(1, 10);  
  p = 101;
  while (n--) {
    int q = random(p, 200);
    a.push_back(q);
    p = q;
  }

  n = random(1, 10);  
  p = 1;
  while (n--) {
    int q = random(p, 100);
    a.push_back(q);
    p = q;
  }

  for (int x : a)
    cout << x << ' ';
  cout << endl;

  set<int> s(a.begin(), a.end());
  for (;;) {
    int x = random(1, 200);
    cout << "x: " << x << endl;
    assert(search(x, a) == s.count(x));
  }
}
