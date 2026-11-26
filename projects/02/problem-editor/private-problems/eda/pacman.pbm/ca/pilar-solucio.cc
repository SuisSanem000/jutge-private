#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef vector< vector<char> > Matriz;
typedef vector< vector<bool> > Visitados;

const int numAd = 4;                    // numero de adyacentes
const int filAd[numAd] = {0, 0, 1, -1}; // filas adyacentes
const int colAd[numAd] = {1, -1, 0, 0}; // columnas adyacentes

void read(Matriz& m, int& fp, int& cp) {
  int f = m.size();
  int c = m[0].size();
  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> m[i][j];
      if (m[i][j] == 'P') {
	fp = i;
	cp = j;  // (fp, cp): posicion del pacman
      }
    }
  }
}

bool ok(const Matriz& m, int f, int c) {
  int fil = m.size();
  int col = m[0].size();
  // mirar si hay fantasma cercano
  for (int i = -1; i <= 1; ++i) 
    for (int j = -1; j <= 1; ++j) {
      if (0 <= f+i and f+i < fil and 0 <= c+j and c+j < col)
	if (m[f+i][c+j] == 'F') return false;
    }
  return true;
}

bool potMenjarBolet(const Matriz& m, int f, int c, Visitados& visit) {
  int fil = m.size();
  int col = m[0].size();
  assert(0 <= f and f < fil);
  assert(0 <= c and c < col);
  if (not visit[f][c]) {
    visit[f][c] = true;
    if (m[f][c] == 'B') return true;
    // hipotesis: m[f][c] != 'X'
    assert(m[f][c] != 'X');
    for (int k = 0; k < numAd; ++k) {
      int ff = f + filAd[k];
      int cc = c + colAd[k]; // k-esimo adyacente
      if (m[ff][cc] != 'X')
	if (ok(m, ff, cc)) {
	  if (potMenjarBolet(m, ff, cc, visit)) return true;
      }
    }
  }
  return false;
}


int main() {
  int f, c;
  while (cin >> f >> c) {
    Matriz m(f, vector<char>(c));
    int fp, cp; // fila y columna del pacman
    read(m, fp, cp);
    Visitados visit(f, vector<bool>(c, false));
    if (not ok(m, fp, cp)) cout << "no" << endl;
    else if (potMenjarBolet(m, fp, cp, visit)) cout << "si" << endl;
    else cout << "no" << endl;
  }
}
