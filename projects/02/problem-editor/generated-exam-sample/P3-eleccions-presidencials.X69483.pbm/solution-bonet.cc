#include <iostream>
#include <map>
#include <string>
using namespace std;

#include "heap.hh"
using namespace pro2;

int main() {
    int umbral;
    cin >> umbral;
    string empresa = "";
    int cant = 0;
    map<string, Heap<int>> contribuciones;

    while (cin >> empresa >> cant) {
        map<string, Heap<int>>::iterator it = contribuciones.find(empresa);
        if (it != contribuciones.end()) {
            (it->second).push(cant);
        } else {
            Heap<int> conj;
            conj.push(cant);
            contribuciones[empresa] = conj;
        }
    }

    map<string, Heap<int>>::iterator it;
    int num = 0;
    int suma = 0;

    for (it = contribuciones.begin(); it != contribuciones.end(); ++it) {
        Heap<int> conj = it->second;
        if (!conj.empty()) {
            suma += conj.top();
            conj.pop();
        }
        if (!conj.empty()) {
            suma += conj.top();
            conj.pop();
        }
        if (!conj.empty()) {
            suma += conj.top();
            conj.pop();
        }
        if (suma > umbral) {
            ++num;
            cout << it->first << endl;
        }
        suma = 0;
    }
    if (num == 0) {
        cout << "eleccions netes!" << endl;
    }
}
