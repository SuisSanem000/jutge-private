// Slow solution: O(N^2) time per case.
// For every peak it scans the peaks to its right looking for one that is at
// least as high, instead of keeping a running maximum. Worst case: strictly
// decreasing sequences, where every peak is compared with all the ones after it.
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

        vector<int> dominant;
        for (int i = 0; i < n; ++i) {
            bool is_dominant = true;
            for (int j = i + 1; j < n && is_dominant; ++j) {
                if (elevations[j] >= elevations[i]) {
                    is_dominant = false;
                }
            }
            if (is_dominant) {
                dominant.push_back(elevations[i]);
            }
        }

        for (int i = 0; i < int(dominant.size()); ++i) {
            cout << dominant[i];
            cout << (i + 1 < int(dominant.size()) ? ' ' : '\n');
        }
    }
}
