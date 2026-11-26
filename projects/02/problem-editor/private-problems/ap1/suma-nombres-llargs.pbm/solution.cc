#include <iostream>
#include <string>
using namespace std;

void gira(string& s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(s[i], s[n - i - 1]);
    }
}

int car_a_enter(char c)
{
    if (c >= 0 and c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

char enter_a_car(int e)
{
    if (e <= 9) {
        return e + '0';
    } else {
        return e + 'A' - 10;
    }
}

string suma(int b, string x, string y)
{
    int m = x.size();
    int n = y.size();
    if (m > n) {
        return suma(b, y, x);
    }
    string z;
    int carry = 0;
    for (int i = 0; i < m; ++i) {
        int valor = carry + car_a_enter(x[m - i - 1]) + car_a_enter(y[n - i - 1]);
        z.push_back(enter_a_car(valor % b));
        carry = valor / b;
    }
    for (int i = m; i < n; ++i) {
        int valor = carry + car_a_enter(y[n - i - 1]);
        z.push_back(enter_a_car(valor % b));
        carry = valor / b;
    }
    if (carry != 0) {
        z.push_back(enter_a_car(carry));
    }
    gira(z);
    return z;
}

int main()
{
    int b;
    string x, y;
    while (cin >> b >> x >> y) {
        cout << suma(b, x, y) << endl;
    }
}
