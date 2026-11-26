#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef map<string, string>::iterator it;
map<string, string> m;

void vaciado(){
   cout << " ***************************** " << endl;
   for (it i=m.begin(); i!=m.end(); ++i) {
    string a=i->first;
    string b=i->second;
    cout << endl << a << " " << b ;   
  }
  cout<< endl << " *********************** " << endl; 
}

void escribir(){ 
  vector<string> v;
  cout << endl << "----------" << endl << "PARELLES:";
  it i=m.begin();
  for (it i=m.begin(); i!=m.end(); ++i) {
    string a=i->first;
    string b=i->second;
    if (a<b and b!="") cout << endl << a << " " << b ;
    if (b=="") v.push_back(a);
  }
  cout << endl << "SOLS:";
  for (int i=0; i<int(v.size()); ++i) cout << endl << v[i];
  cout << endl << "----------";
//  vaciado();
}

int main(){
  string s1, p1, p2, ep1, ep2;
  while (cin >> s1) {
    if (s1=="info") escribir();
    else { // caso "liats"
      cin >> ep1 >> ep2;
      if (ep1 > ep2) {p1=ep2; p2=ep1;
      } else { p1=ep1; p2=ep2;}
       // p1 < p2 siempre
      it ip1=m.find(p1);     
      it ip2=m.find(p2);
      if (ip1!=m.end()) { // p1 existe
        if (m[p1]==p2) cout << endl << "ERROR: "<< ep1 << " i " << ep2 << " ja estan liats";
        else { 
          if (m[p1]!="") m[m[p1]]=""; 
          m[p1]=p2;
          if (ip2!=m.end() and m[p2]!="") m[m[p2]]="";
          m[p2]=p1;
        }
      } else { // p1 no existe
        m[p1]=p2;
        if (ip2!=m.end() and m[p2]!="") m[m[p2]]="";
        m[p2]=p1;
      }
//      vaciado();
    }
  }
}
