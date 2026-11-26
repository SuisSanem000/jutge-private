#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int x, n;
VE M;


int f(int i, int sum) {
  if (sum > x) return 0;
  if (i == n) return sum == x;
  int res = 0;
  for (int k = 0; k <= 2; ++k) res += f(i + 1, sum + k*M[i]);
  return res;
}


int main() {
  while (cin >> x >> n) {
    M = VE(n);
    for (int i = 0; i < n; ++i) cin >> M[i];
    cout << f(0, 0) << endl;
  }
}
