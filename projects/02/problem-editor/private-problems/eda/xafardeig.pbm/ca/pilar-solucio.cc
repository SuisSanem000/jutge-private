#include <iostream>
#include <map>
#include <set>
#include <cstdlib>
using namespace std;

typedef map<string, string> Relations;
typedef set<string> Set;

typedef Relations:: iterator ItR;
typedef Set:: iterator ItS;

void cambiar(string& a, string& b) {
  string aux;
  aux = a;
  a = b;
  b = aux;
}

void info(Relations& liats, Set& sols) {
  cout << "PARELLES:" << endl;
  ItR itr;
  for (itr = liats.begin(); itr != liats.end(); ++itr)
    cout << itr->first << " " << itr->second << endl;
  ItS its;
  cout << "SOLS:" << endl;
  for (its = sols.begin(); its != sols.end(); ++its)
    cout << *its << endl;
  cout << "----------" << endl;
} 

// busca si existe x tal que a->x; si existe: borra a->x y añade x a sols
// busca si existe x tal que x->a; si existe: borra x->a y añade x a sols
void lioCon(const string& a, Relations& liats, Relations& inver, Set& sols) {
  ItR itr;
  // busca si existe x tal que a->x
  itr = liats.find(a);
  if (itr != liats.end()) {     // existe a->x
    string x = itr->second;
    sols.insert(x);            // añadir x a sols
    liats.erase(itr);          // borrar a->x
    ItR itr1 = inver.find(x);      // borrar x->a de inver
    inver.erase(itr1);
  }
  // busca si existe x tal que x->a
  ItR itv;
  itv = inver.find(a);        // en inver busco a
  if (itv != inver.end()) {   //existe a->x en inver => existe x->a en liats, debe ser x<a 
    string x = itv->second;
    sols.insert(x);          //añadir x a sols        
    inver.erase(itv);       // borrar a->x en inver
    if (x < a) {
      ItR itv2 = liats.find(x);
      liats.erase(itv2);     // borrar x->a en liats
    }
  }
}

// añade a->b y quita a de solos, quita b de solos
void add(const string& a, const string& b, Relations& liats, Relations& inver, Set& sols) {
  ItS its;
  // borra a de sols
  its = sols.find(a);
  if (its != sols.end()) {
    sols.erase(its);
  }
  // borra b de sols
  its = sols.find(b);
  if (its != sols.end()) {
    sols.erase(its);
  }
  // añade a->b
  if (a < b) {
    liats.insert(pair<string, string>(a, b));
    inver.insert(pair<string, string>(b, a));
  }
  else {
    liats.insert(pair<string, string>(b, a));
    inver.insert(pair<string, string>(a, b));
  }
}

void liar(Relations& liats, Relations& inver, Set& sols) {
  string a, b;
  cin >> a >> b;
  if (a > b) cambiar(a, b); // a es menor que b
// AÑADIR a->b:
  // buscar si hay alguien liado con a y quitarlo 
  lioCon(a, liats, inver, sols);
  // buscar si hay alguien liado con b y quitarlo
  lioCon(b, liats, inver, sols);
  // añadir a->b
  add(a, b, liats, inver, sols);
}

int main() {
  Relations liats; // contiene los liados a->b con a<b
  Relations inver; // contiene la inversa de liados: si a->b in liats => b->a in inver
  Set sols;
  string s;
  while (cin >> s) {
    if (s == "info") info(liats, sols);
    else liar(liats, inver, sols);
  }

}
