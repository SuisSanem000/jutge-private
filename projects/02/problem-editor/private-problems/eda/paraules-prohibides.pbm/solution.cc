#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE solu, usat;


void f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j) cout << char(solu[j] + 'a');
    cout << endl;
    return;
  }

  for (int j = 0; j < n; ++j)
    if (not usat[j] and (i == 0 or solu[i-1] + 1 != j)) {
      usat[j] = true;
      solu[i] = j;
      f(i + 1);
      usat[j] = false;
    }
}


int main() {
  cin >> n;
  solu = VE(n);
  usat = VE(n, false);
  f(0);
}
