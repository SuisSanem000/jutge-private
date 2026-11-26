
#include <cassert>

/**
 * @pre n >= 0
 * @post Returns true if number is of form: a^nb^m, where a != b, n, m > 0
 */
bool is_bicolor(int n) {
    // Primera parte: digit1 repetido
    int d1 = n % 10;
    n /= 10;
    while (n > 0 && n % 10 == d1) {
        n /= 10;
    }

    // Si todas las cifras eran iguales, no es bicolor
    if (n == 0) {
        return false;
    }

    // Segunda parte: digit2 repetido
    int d2 = n % 10;
    n /= 10;
    while (n > 0 && n % 10 == d2) {
        n /= 10;
    }

    // Es bicolor si ya no quedan cifras
    return n == 0;
}
