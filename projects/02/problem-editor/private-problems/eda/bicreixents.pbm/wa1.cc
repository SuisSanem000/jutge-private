#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

int index(const vector<int>& a, int l, int r) {
  while (l+1 < r) {
    int m = (l+r)/2;
    if (a[l] < a[m]) l = m;
    else              r = m;
  }
  return l;
}

bool bin_search(const vector<int>& a, int l, int r, int x) {
  while (l <= r) {
    int m = (l+r)/2;
    if      (a[m] < x) l = m+1;
    else if (a[m] > x) r = m-1;
    else return true;
  }
  return false;
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
