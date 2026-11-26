#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

bool search(int x, const vector<int>& a) {
  return find(a.begin(), a.end(), x) != a.end();
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
