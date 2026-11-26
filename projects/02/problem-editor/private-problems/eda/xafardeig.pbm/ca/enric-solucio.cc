#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string,string> M;

int main() {
  M m;
  string op;
  while (cin >> op) {
    if (op == "liats") {
      string name1, name2;
      cin >> name1 >> name2;
      string& p1 = m[name1];
      string& p2 = m[name2];
      if (p1 != "") m[p1] = "";
      if (p2 != "") m[p2] = "";
      p1 = name2;
      p2 = name1;
    }
    else {
      cout << "PARELLES:" << endl;
      for (M::iterator k = m.begin(); k != m.end(); ++k)
        if (k->second != "" and k->first < k->second)
          cout << k->first << " " << k->second << endl;

      cout << "SOLS:" << endl;
      for (M::iterator k = m.begin(); k != m.end(); ++k)
        if (k->second == "")
          cout << k->first << endl;
      cout << "----------" << endl;
    }
  }
}
