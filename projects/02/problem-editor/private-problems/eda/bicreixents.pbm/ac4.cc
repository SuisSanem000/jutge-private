#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

int index(const vector<int>& a, int l, int r) {
  if (r == l+1) return l;
  int m = (l+r)/2;
  if (a[l] <= a[m]) return index(a, m, r);
  else              return index(a, l, m);
}

bool bin_search(const vector<int>& a, int l, int r, int x) {
  if (l > r) return false;
  int m = (l+r)/2;
  if (a[m] < x) return bin_search(a, m+1, r,  x);
  if (a[m] > x) return bin_search(a,  l, m-1, x);
  return true;
}

bool search(const vector<int>& a, int x) {
  int n = a.size();
  int j = index(a, 0, n-1);
  return bin_search(a, 0, j, x) or bin_search(a, j+1, n-1, x);
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
    assert(search(a, x) == s.count(x));
  }
}
