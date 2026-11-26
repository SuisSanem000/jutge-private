#include <iostream>
#include <list>
using namespace std;

/**
 * @brief Ordena un rang d'una llista usant selecció.
 *
 * @param begin Iterador al principi del rang.
 * @param end Iterador al final del rang (no inclòs).
 *
 * @pre begin i end delimiten un rang vàlid d'una llista.
 * @post El rang [begin, end) queda ordenat ascendentment.
 */
void ordenacio_seleccio(list<int>::iterator begin, list<int>::iterator end);

list<int> llegeix_llista() {
    list<int> L;
    int val;
    while (cin >> val) {
        L.push_back(val);
    }
    return L;
}

void escriu_llista(const list<int>& L) {
    if (L.empty()) {
        cout << "<buida>" << endl;
        return;
    }
    auto it = L.begin();
    cout << *it;
    for (++it; it != L.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}

int main() {
    list<int> L = llegeix_llista();

    // Cridem a la funció d'interès
    ordenacio_seleccio(L.begin(), L.end());

    escriu_llista(L);
    return 0;
}