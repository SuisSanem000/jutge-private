#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            sum += x;
        }
    }
    cout << sum << endl;
    return 0;
}
