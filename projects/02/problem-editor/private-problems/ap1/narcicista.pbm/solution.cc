#include <iostream>
using namespace std;

int potencia(int a, int b)
{
    int r = 1;
    while (b != 0) {
        r = r * a;
        --b;
    }
    return r;
}

int nombre_digits(int x)
{
    int n = 0;
    while (x > 0) {
        x /= 10;
        ++n;
    }
    return n;
}

bool es_narcisista(int n)
{
    int k = nombre_digits(n);
    int suma = n, i = 0;
    while (i < k and suma >= 0) {
        suma -= potencia(n % 10, k);
        n /= 10;
        ++i;
    }
    return suma == 0;
}

int main()
{
    int n, fin = true;
    while (cin >> n and fin) {
        fin = es_narcisista(n);
    }
    if (fin)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}