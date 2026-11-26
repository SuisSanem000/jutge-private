#include <iostream>
#include <vector>
using namespace std;

using Fila = vector<int>;
using Matriu = vector<Fila>;

Matriu llegir_matriu()
{
    int n;
    cin >> n;
    Matriu matriu(n, Fila(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriu[i][j];
        }
    }
    return matriu;
}

void escales(const Matriu& matriu, int inici, int final, int limit)
{
    cout << inici << " " << final << " " << limit << ":";
    int n = matriu.size();
    bool algun = false;
    for (int escala = 0; escala < n; ++escala) {
        if (matriu[inici][escala] + matriu[escala][final] <= limit) {
            cout << " " << escala;
            algun = true;
        }
    }
    if (not algun) {
        cout << " res";
    }
    cout << endl;
}

int main()
{
    Matriu matriu = llegir_matriu();

    int inici, final, limit;
    while (cin >> inici >> final >> limit) {
        escales(matriu, inici, final, limit);
    }
}
