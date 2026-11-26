#include <iostream>
#include <string>

using namespace std;

void escriure_paraules_rec(int i, string& w, char c, int n)
{
    if (i == n) {
        cout << w << endl;
    } else {
        for (char cc = c + 2; cc <= 'z'; ++cc) {
            w[i] = cc;
            escriure_paraules_rec(i + 1, w, w[i], n);
        }
    }
}

void escriure_paraules(int n, char c)
{
    string w(n, c); // crea string amb n cops el caràcter c (només el primer importa)
    escriure_paraules_rec(1, w, c, n);
}

int main()
{
    int n;
    char c;
    cin >> n >> c;
    escriure_paraules(n, c);
}
