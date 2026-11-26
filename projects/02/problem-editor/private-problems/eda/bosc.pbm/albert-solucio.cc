#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Graph;

bool dfs(const Graph& G, vector<bool>& vis, int u, vector<int>& pare) {
    bool ho_es = true;
    for (int i = 0; i < int(G[u].size()) and ho_es; ++i) {
        int v = G[u][i];
        if (vis[v]) { 
            if (pare[u] != v) ho_es = false;
        } else {
            pare[v] = u; vis[v] = true;
            ho_es = dfs(G, vis, v, pare);
        }
    }
    return ho_es;
}

int es_bosc(const Graph& G) {
    int n = G.size();
    vector<bool> vis(n, false);
    vector<int> pare(n, -1);
    bool ho_es = true;
    int q = 0;
    for (int u = 0; u < n and ho_es; ++u) {
        if (not vis[u]) {
            ++q;
            vis[u] = true;
            ho_es = dfs(G, vis, u, pare);
        }
    }
    if (ho_es) return q;
    else return -1;
}


int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int q = es_bosc(G);
        if (q < 0) cout << "no" << endl;
        else cout << q << endl;
    }
}
