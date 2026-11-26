#include <iostream>
#include <vector>
using namespace std;

vector<int> read() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    return v;
}

int count_pairs(const vector<int>& v, int m) {
    int n = v.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((v[i] + v[j])%m == 0) ++count;
        }
    }
    return count;
}

int main() {
    int m;
    while (cin >> m) {
        cout << count_pairs(read(), m) << endl;
    }
}