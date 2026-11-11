#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> elevations(n);
        for (int i = 0; i < n; ++i) {
            cin >> elevations[i];
        }

        // Scan from right to left, keeping the highest elevation seen so far.
        // A peak is dominant when it is strictly higher than that maximum.
        vector<int> dominant;
        long long highest = -2000000000LL;
        for (int i = n - 1; i >= 0; --i) {
            if (elevations[i] > highest) {
                dominant.push_back(elevations[i]);
                highest = elevations[i];
            }
        }

        // The peaks were collected right to left, so print them in reverse.
        for (int i = int(dominant.size()) - 1; i >= 0; --i) {
            cout << dominant[i];
            cout << (i > 0 ? ' ' : '\n');
        }
    }
}
