#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
  srand(2345);
  
  int ncasos = 100;
  for (int i = 0; i < ncasos; ++i) {
    int m = rand()%20 + 1;
    int n = rand()%30;
    cout << m << " " << n;
    for (int j = 0; j < n; ++j) {
      if (rand()%100 > 60) { // múltiplo
	cout << " " << m*(rand()%100);
      } 
      else cout << " " << rand()%100;
    }
    cout << endl;
  } 
}
