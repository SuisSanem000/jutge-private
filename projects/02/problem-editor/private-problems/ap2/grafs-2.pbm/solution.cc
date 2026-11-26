#include <iostream>
#include <map>
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
    int n;
    cin >> n;

    map<string, int> ids;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ids[s] = i;
    }

    int m;
    cin >> m;

    Graf G(n);
    for (int i = 0; i < m; ++i) {
        string su, sv;
        cin >> su >> sv;
        int u = ids[su];
        int v = ids[sv];
        G[u].push_back(v);
    }

    string sx, sy;
    cin >> sx >> sy;
    int x = ids[sx];
    int y = ids[sy];

    // fer el recorregut
    vector<bool> vis(n, false);
    dfs(G, x, vis);
    cout << (vis[y] ? "yes" : "no") << endl;
}
