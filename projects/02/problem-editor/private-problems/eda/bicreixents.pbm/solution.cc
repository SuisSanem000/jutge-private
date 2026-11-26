// cost log^2


#include <iostream>
#include <vector>
using namespace std;


bool dico(int x, int e, int d, const vector<int>& v) {
  if (e > d) return false;
  int m = (e + d)/2;
  if (x < v[m]) return dico(x, e, m - 1, v);
  if (x > v[m]) return dico(x, m + 1, d, v);
  return true;
}


bool isearch(int x, int e, int d, const vector<int>& v) {
  if (e + 1 == d) return v[e] == x or v[d] == x;
  int m = (e + d)/2;
  if (v[m] >= v[e]) return dico(x, e, m, v) or isearch(x, m, d, v);
  return dico(x, m, d, v) or isearch(x, e, m, v);
}


bool search(int x, const vector<int>& v) {
  return isearch(x, 0, v.size() - 1, v);
}
