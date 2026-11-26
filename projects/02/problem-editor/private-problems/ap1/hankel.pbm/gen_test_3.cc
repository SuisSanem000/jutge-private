#include <iostream>
using namespace std;


int main() {
  cout << 2 << endl;
  cout << endl;
  cout << 200 << endl;
  for (int i = 0; i < 200; ++i) {
    for (int j = 0; j < 200; ++j)
      if (i == 100 and j == 100) cout << 1 << ' ';
      else cout << 0 << ' ';
    cout << endl;
  }
  cout << endl;
  cout << 200 << endl;
  for (int i = 0; i < 200; ++i) {
    for (int j = 0; j < 200; ++j)
      cout << i + j << ' ';
    cout << endl;
  }
}
