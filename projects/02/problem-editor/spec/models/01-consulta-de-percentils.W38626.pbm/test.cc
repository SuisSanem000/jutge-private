#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Jugador {
    string nom;
    int punts;
    double percentil;
};

bool fcomp(const Jugador& a, const Jugador& b) {
    return a.punts > b.punts;
}

int main() {
    cout.precision(2);
    cout.setf(ios::fixed);

    vector<Jugador> jugadors;

    string nom;
    int puntuacio;

    cin >> nom;
    while (nom != "---") {
        cin >> puntuacio;
        jugadors.push_back({nom, puntuacio, 0});
        cin >> nom;
    }

    sort(jugadors.begin(), jugadors.end(), fcomp);
    int n = jugadors.size();
    for (int i = 0; i < n; i++) {
        jugadors[i].percentil = (100.0 / n) * (n - i);
    }

    int m = jugadors.size();
    while (cin >> nom) {
        for (int i = 0; i < m; i++) {
            if (nom == jugadors[i].nom) {
                cout << jugadors[i].percentil << endl;
            }
        }
    }
}
