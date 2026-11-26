#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
using namespace std;

int main() {
  const int P = 50;     // nb of games
  const int N = 100;    // nb of players
  const int E = 5;

  srand(5363);
  cout << P << endl << N << endl;
  for (int i = 0; i < N; ++i) {
    cout << char('a' + rand()%10) << i; // nombre jugador: no repes
    for (int j = 0; j < P; ++j) {
      for (int k = 0; k < E; ++k) {
	int c = rand()%5;
	if (c == 0) cout << " " << rand()%10;           // 20% probable
	else if (c < 3) cout << " " << 10 + rand()%10;  // 40%
	else cout << " " << 20 + rand()%10;             // 40%
      }
    }
    cout << endl;
  }
}
