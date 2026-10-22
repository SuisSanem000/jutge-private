#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        int sum_primes = 0;
        for (int i = 2; i <= n; ++i) {
            if (is_prime(i)) {
                sum_primes += i;
            }
        }
        cout << sum_primes << "\n";
    }
    return 0;
}
