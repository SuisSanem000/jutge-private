#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int> > graf;

int main() {
    int n, m;
    while (cin >> n >> m) {
        graf G(n);
        vector<int> grau_e(n,0);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            ++grau_e[y];
        }
        priority_queue<int> Q;
        for (int i = 0; i < n; ++i) if (grau_e[i] == 0) Q.push(-i);
        bool primer = true;
        while (not Q.empty()) {
            int v = -Q.top(); Q.pop();
            if (primer) {primer = false; cout << v;}
            else cout << " " << v;
            for (int i = 0; i < int(G[v].size()); ++i) {
               if (--grau_e[G[v][i]] == 0) Q.push(-G[v][i]);        
            }
        }
        cout << endl;
    }
}
