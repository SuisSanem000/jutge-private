
#define main main__3

#include <cassert>

int pop_digit(int& n) {
    int digit = n % 10;
    n /= 10;
    return digit;
}

/**
 * @pre n >= 0
 * @post Returns true if number is of form: a^nb^m, where a != b, n, m > 0
 */
bool is_bicolor(int n) {
    // Primera parte: digit1 repetido
    int d1 = pop_digit(n);
    while (n > 0 && pop_digit(n) == d1)
        ;

    // Si todas las cifras eran iguales, no es bicolor
    if (n == 0) {
        return false;
    }

    // Segunda parte: digit2 repetido
    int d2 = pop_digit(n);
    while (n > 0 && pop_digit(n) == d2)
        ;

    // Es bicolor si ya no quedan cifras
    return n == 0;
}

#undef main
#define main main__2

#include <iostream>
using namespace std;

#include "is_bicolor.cc"

int main() {
    int n;
    while (cin >> n) {
        cout << n << '\t' << (is_bicolor(n) ? "SI" : "NO") << endl;
    }
}

#undef main

int main() {
    return main__2();
}
