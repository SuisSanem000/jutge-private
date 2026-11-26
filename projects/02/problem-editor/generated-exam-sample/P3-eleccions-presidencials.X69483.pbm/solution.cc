#include <iostream>
#include <map>
using namespace std;

// Posa els includes necessaris per als contenidors
// que necessitis i fes el programa principal.

struct Item {
    int suma, qmax1, qmax2, qmax3;
};

int main() {
    int n;
    cin >> n;

    map<string, Item> m;
    string empresa;
    int quantitat;
    bool eleccions_netes = true;
    while (cin >> empresa >> quantitat) {
        auto it = m.find(empresa);
        if (it == m.end()) {
            m[empresa] = {quantitat, quantitat, 0, 0};
        } else {
            // Actualitzem les 3 contribucions més grans i la suma
            Item& item = it->second;
            if (quantitat > item.qmax1) {
                item.suma += quantitat - item.qmax1;
                swap(item.qmax1, quantitat);
            }
            if (quantitat > item.qmax2) {
                item.suma += quantitat - item.qmax2;
                swap(item.qmax2, quantitat);
            }
            if (quantitat > item.qmax3) {
                item.suma += quantitat - item.qmax3;
                swap(item.qmax3, quantitat);
            }
            if (item.suma > n) {
                eleccions_netes = false;
            }
        }
    }
    if (eleccions_netes) {
        cout << "eleccions netes!" << endl;
    } else {
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second.suma > n) {
                cout << it->first << endl;
            }
        }
    }
}
