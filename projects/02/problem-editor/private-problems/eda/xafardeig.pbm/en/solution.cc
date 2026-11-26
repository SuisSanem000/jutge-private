#include <iostream>
#include <map>
using namespace std;


typedef map<string, string> MSS;
typedef MSS::iterator MI;


int main() {
  MSS M;
  string s;
  while (cin >> s)
    if (s == "affair") {
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
      cout << "COUPLES:" << endl;
      for (MI p = M.begin(); p != M.end(); ++p)
        if (p->first < p->second)
          cout << p->first << ' ' << p->second << endl;
      cout << "ALONE:" << endl;
      for (MI p = M.begin(); p != M.end(); ++p)
        if (p->second == "") cout << p->first << endl;
      cout << "----------" << endl;
    }
}
