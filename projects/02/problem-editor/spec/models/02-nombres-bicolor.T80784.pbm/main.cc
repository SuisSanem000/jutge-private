#include <iostream>
using namespace std;

bool is_bicolor(int n);

int main() {
    int n;
    while (cin >> n) {
        if (is_bicolor(n)) {
            cout << n << endl;
        }
    }
    return 0;
}
