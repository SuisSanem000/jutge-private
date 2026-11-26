#include <iostream>

using namespace std;

int num_digits(int n, int b)
{
    if (n < b)
        return 1;
    return 1 + num_digits(n / b, b);
}

bool es_creixent_decreixent_rec(int b, int n, bool alt)
{
    if (n < b * b)
        return true;
    int ud = n % b;
    int apud = ((n / b) / b) % b;
    if (alt and ud <= apud)
        return false;
    if ((not alt) and ud >= apud)
        return false;
    return es_creixent_decreixent_rec(b, n / b, not alt);
}

bool es_creixent_decreixent(int b, int n)
{
    return es_creixent_decreixent_rec(b, n, num_digits(n, b) % 2 == 1);
}

void escriu_en_base(int n, int b)
{
    if (n < b)
        cout << n;
    else {
        escriu_en_base(n / b, b);
        cout << " " << n % b;
    }
}

int main()
{
    int b, n;
    while (cin >> b >> n) {
        if (es_creixent_decreixent(b, n)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        // cout << " " << n << " " << b << " : ";
        // escriu_en_base(n, b);
        cout << endl;
    }
}
