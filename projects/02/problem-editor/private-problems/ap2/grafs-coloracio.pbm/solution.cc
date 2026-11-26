#include <iostream>
#include <set>
#include <vector>
using namespace std;

using Graf = vector<vector<int>>; // llistes d'ajacència

Graf llegir_graf(int n, int m)
{
    Graf G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    return G;
}

int golafre(const Graf& G)
{
    const int n = G.size();
    vector<int> cols(n, -1); // coloració del graf (-1 == no colorejat encara)
    int k = 0; // nombre de colors emprats

    for (int u = 0; u < n; ++u) {
        set<int> C;
        for (int v : G[u]) {
            if (cols[v] != -1) {
                C.insert(cols[v]);
            }
        }
        // C és el conjunt dels colors dels veïns pintats de u.
        int c = 0;
        while (C.count(c)) {
            ++c;
        }
        cols[u] = c;
        if (c == k)
            ++k;
    }

    return k;
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        Graf G = llegir_graf(n, m);
        cout << golafre(G) << endl;
    }
}
