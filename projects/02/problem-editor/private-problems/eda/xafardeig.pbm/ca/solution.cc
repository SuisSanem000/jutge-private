#include <iostream>
#include <map>
using namespace std;


typedef map<string, string> MSS;
typedef MSS::iterator MI;


int main() {
  MSS M;
  string s;
  while (cin >> s)
    if (s == "liats") {
      string x, y;
      cin >> x >> y;
      if (M[x] == y) cerr << "ERROR: " << x + " i " + y + " ja estan liats" << endl;
      else {
        if (M[x] != "") M[M[x]] = "";
        if (M[y] != "") M[M[y]] = "";
        M[x] = y;
        M[y] = x;
      }
    }
    else {
      cout << "PARELLES:" << endl;
      for (MI p = M.begin(); p != M.end(); ++p)
        if (p->first < p->second)
          cout << p->first << ' ' << p->second << endl;
      cout << "SOLS:" << endl;
      for (MI p = M.begin(); p != M.end(); ++p)
        if (p->second == "") cout << p->first << endl;
      cout << "----------" << endl;
    }
}
