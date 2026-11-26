#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "heap.hh"
#include "pacient.hh"
using namespace pro2;

/** Acumulat de temps d'espera i nombre d'atèsos per una prioritat (per calcular la mitjana). */
struct DadesEspera {
    double suma_espera = 0;
    int num_atesos = 0;
};

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    Heap<Pacient> espera;

    // Posició 0 no es fa servir; prioritats vàlides 1, 2, 3
    vector<DadesEspera> per_prioritat(4);

    string event;
    while (cin >> event) {
        if (event == "arriba") {
            Pacient p;
            cin >> p.id >> p.prioritat >> p.timestamp;
            espera.push(p);
        } else if (event == "seguent") {
            int ts;
            cin >> ts;
            Pacient p = espera.top();
            espera.pop();
            cout << p.id << endl;
            int espera_temps = ts - p.timestamp;
            DadesEspera& ac = per_prioritat[p.prioritat];
            ac.suma_espera += espera_temps;
            ac.num_atesos++;
        }
    }

    for (int p = 1; p <= 3; p++) {
        const DadesEspera& ac = per_prioritat[p];
        if (ac.num_atesos > 0) {
            cout << "prioritat " << p << ": " << ac.suma_espera / ac.num_atesos << endl;
        }
    }
}
