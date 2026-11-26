#include <iostream>
using namespace std;

// retorna el nombre de dígits d'un natural x en base b (amb b >= 2)
int digits(int x, int b)
{
    int d = 1;
    while (x >= b) {
        x /= b;
        ++d;
    }
    return d;
}

// donats dos naturals x i y, desa en b quina éss la base méss petita (amb b ≥ 2)
// en la qual x i y tenen el mateix nombre de dígits,
// i desa en n el nombre de dígits de x i y en aquesta base.
void base_amb_mateix_nombre_de_digits(int x, int y, int& b, int& n)
{
    for (b = 2; true; ++b) {
        n = digits(x, b);
        if (digits(y, b) == n) {
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
        cout << x << " " << y << " " << b << " " << n << endl;
    }
}
