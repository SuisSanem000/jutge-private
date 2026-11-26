#include <iostream>
#include <map>
#include <numeric>
#include <set>
using namespace std;

int main() {
    int limite;
    map<string, multiset<int>> contrib;

    cin >> limite;

    string nombre;
    int cantidad;
    while (cin >> nombre >> cantidad) {
        auto& v = contrib[nombre];
        if (v.size() < 3 || cantidad > *v.begin()) {
            v.insert(cantidad);
            if (v.size() > 3) {
                v.erase(v.begin());
            }
        }
    }

    bool some = false;
    for (auto it = contrib.begin(); it != contrib.end(); ++it) {
        if (accumulate((it->second).begin(), (it->second).end(), 0) > limite) {
            cout << it->first << "\n";
            some = true;
        }
    }
    if (!some) {
        cout << "eleccions netes!\n";
    }

    return 0;
}