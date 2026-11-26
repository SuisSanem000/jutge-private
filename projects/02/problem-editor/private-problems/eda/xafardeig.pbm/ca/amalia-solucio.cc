#include<iostream>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

typedef set<string> couple;
typedef set<couple>::iterator ite;
typedef set<string>::iterator its;

int main() {
  set<couple> L;
  set<string> S;
  string s;
  while(cin >> s) {
    if (s == "info") {
      cout << "----------" << endl << "PARELLES:" << endl;
      for (ite i = L.begin(); i != L.end(); ++i) {
	its j = (*i).begin(); 
	cout << *j << " "; ++j; cout << *j << endl;
      }
      cout << "SOLS:" << endl;
      for (its it = S.begin(); it != S.end(); ++it) {
	cout << *it << endl;
      }
      cout << "----------" << endl;
    }
    else {
      string x, y;
      cin >> x >> y;
      S.erase(x); S.erase(y);
      couple c, d1, d2; 
      c.insert(x); c.insert(y);
      for (ite i = L.begin(); i != L.end(); ++i) {
	couple d = *i;
	  if (c == d) 
	      cout << "ERROR: " << x << " i " << y << " ja estan liats" << endl;
	  else if (d.find(x) != d.end()) {
	      its j = d.begin();
	      if (*j != x) S.insert(*j);
	      else {++j; S.insert(*j);}
	      d1 = d; 
	  }
	  else if (d.find(y) != d.end()) {
	      its j = d.begin();
	      if (*j != y) S.insert(*j);
	      else {++j; S.insert(*j);} 
	      d2 = d; 
	  } 
      }
      L.erase(d1); L.erase(d2); L.insert(c);
    }
  }
}

