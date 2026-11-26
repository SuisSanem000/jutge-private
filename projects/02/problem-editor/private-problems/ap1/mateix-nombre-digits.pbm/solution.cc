#include <iostream>
using namespace std;

// indica si x i y tenen el mateix nombre de dígits en base b
// i, en cas afirmatiu, desa en n aquest nombre de dígits.
bool mateix_nombre_de_digits(int x, int y, int b, int& n)
{
    n = 1;
    while (x >= b and y >= b) {
        x /= b;
        y /= b;
        ++n;
    }
    return x < b and y < b;
}

// donats dos naturals x i y, desa en b quina és la base més petita (amb b ≥ 2)
// en la qual x i y tenen el mateix nombre de dígits,
// i desa en n el nombre de dígits de x i y en aquesta base.
void base_amb_mateix_nombre_de_digits(int x, int y, int& b, int& n)
{
    for (b = 2; true; ++b) {
        if (mateix_nombre_de_digits(x, y, b, n)) {
            return;
        }
    }
}

int main()
{
    int x, y;
    while (cin >> x >> y) {
        int b, n;
        base_amb_mateix_nombre_de_digits(x, y, b, n);
        cout << b << " " << n << endl;
    }
}
