#include <iostream>

using namespace std;

void patro(int n)
{
    if (n > 0) {
        cout << 'a';
        patro(n - 1);
        cout << 'b';
        patro(n - 1);
        cout << 'c';
    }
}

int main()
{
    int n;
    while (cin >> n) {
        patro(n);
        cout << endl;
    }
}
