#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, xmax, hmax;

    cout << "n xmax hmax: ";
    cin >> n >> xmax >> hmax;
    srand(time(NULL));

    vector<int> x(n);
    vector<int> h(n);

    for (int i = 0; i < n; ++i) {
        x[i] = rand() % xmax;
        do {
            h[i] = rand() % hmax;
        } while (i != 0 and h[i] == h[i - 1]);
    }

    h[n - 1] = 0;
    while (h[n - 2] == 0 or h[n - 2] == h[n - 3]) {
        h[n - 2] = rand() % hmax;
    }

    sort(x.begin(), x.end());

    for (int i = 1; i < n; ++i) {
        if (x[i] <= x[i - 1])
            x[i] = x[i - 1] + 1;
    }

    cout << n << endl;
    for (int i = 0; i < n; ++i)
        cout << x[i] << ' ' << h[i] << endl;
}