#include "atzar.cc"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;


typedef vector<char> VC;
typedef set<string> SS;
typedef vector<SS> VSS;


atzar A(0);


VC C;
VSS S;


string st(int x) {
  stringstream ss;
  ss << x;
  string s;
  ss >> s;
  return s;
}


string par() {
  string s;
  int m = A.uniforme(4, 6);
  while (m--) s += 'a' + A.uniforme(0, 25);
  return s;
}


int main() {
  for (int p = 100; p <= 120; ++p) {
    string s = "prova-" + st(p) + ".inp";
    ofstream ofs(s.c_str());
    if (!ofs) {
      cout << "ERROR OBRINT EL FITXER " << s << endl;
      return -1;
    }

    int m = (p == 120 ? 50000 : A.uniforme(100, 1000));
    int n = (p == 120 ? 10000 : 3 + 3*(119 - p));
    double prob = (p == 120 ? 0.9992 : 0.9);

    SS S;
    while ((int)S.size() < n) S.insert(par());
    vector<string> V(S.begin(), S.end());

    map<string, string> M;
    while (m--) {
      if (A.probabilitat(prob)) {
        int i = A.uniforme(0, n - 1);
        int j;
        do j = A.uniforme(0, n - 1);
           while (j == i or M[V[i]] == V[j]);
        ofs << "liats " << V[i] << ' ' << V[j] << endl;
        string p1 = M[V[i]];
        string p2 = M[V[j]];
        M[V[i]] = V[j];
        M[V[j]] = V[i];
        M[p1] = M[p2] = "";
      }
      else ofs << "info" << endl;
    }
    if (p == 120) ofs << "info" << endl;
  }
}
