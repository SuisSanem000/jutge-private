#include <iostream>
#include <vector>
using namespace std;

using Graf = vector<vector<int>>;

void dfs(const Graf& G, int u, vector<bool>& vis)
{
    if (not vis[u]) {
        vis[u] = true;
        for (int v : G[u])
            dfs(G, v, vis);
    }
}

int main()
{
    // llegir mides
    int n, m;
    cin >> n >> m;

    // llegir el graf
    Graf G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    // llegir font i destí
    int x, y;
    cin >> x >> y;

    // fer el recorregut
    vector<bool> vis(n, false);
    dfs(G, x, vis);
    cout << (vis[y] ? "yes" : "no") << endl;
}
