
#include <iostream>
#include <list>
#include <map>
using namespace std;

list<pair<string, int>> all_pairs(map<string, int>& M);

int main() {
    string s;
    int n;
    map<string, int> M;
    while (cin >> s >> n) {
        M[s] = n;
    }
    list<pair<string, int>> L = all_pairs(M);
    list<pair<string, int>>::iterator it = L.begin();
    for (; it != L.end(); it++) {
        cout << it->first << ' ' << it->second << endl;
    }
}
