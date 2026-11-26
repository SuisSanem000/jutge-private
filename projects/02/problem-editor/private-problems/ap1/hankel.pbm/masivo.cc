#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
  srand(2345);
  int ncasos = 200;
  cout << ncasos << endl;
  cout << endl;
  for (int k = 0; k < ncasos; ++k) {
    int m = 1 + rand()%10;
    cout << m << endl;
    vector< vector<int> > mat(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
	if (i == 0 or j == m - 1 ) 
	  mat[i][j] = rand()%100;
	else if (rand()%150 == 0)  mat[i][j] = rand()%100;
	else  mat[i][j] = mat[i - 1][j + 1];
	cout << mat[i][j] << ' ';                  
      }
      cout << endl;
    }
    cout << endl;
  }
}
