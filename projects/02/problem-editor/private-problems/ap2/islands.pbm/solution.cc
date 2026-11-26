#include <iostream>
#include <vector>
using namespace std;

using Mapa = vector<string>;
using MatBool = vector<vector<bool>>;

const char TERRA = 'O';

// diu si (i,j) pertany al mapa i si hi ha terra a la posició (i,j) del mapa
bool terra(int i, int j, const Mapa& mapa)
{
    int n = mapa.size();
    int m = mapa[0].size();
    return i >= 0 and j >= 0 and i < n and j < m and mapa[i][j] == TERRA;
}

void dfs(const Mapa& mapa, MatBool& vis, int i, int j)
{
    if (not vis[i][j]) {
        vis[i][j] = true;
        // ho he fet així de lleig perquè em calia posar-ho en C++11.
        for (pair<int, int> d : vector<pair<int, int>> { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } }) {
            if (terra(i + d.first, j + d.second, mapa))
                dfs(mapa, vis, i + d.first, j + d.second);
        }
    }
}

int illes(const Mapa& mapa)
{
    int n = mapa.size();
    int m = mapa[0].size();
    MatBool vis(n, vector<bool>(m, false));
    int c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mapa[i][j] == TERRA and not vis[i][j]) {
                ++c;
                dfs(mapa, vis, i, j);
            }
        }
    }
    return c;
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        Mapa mapa(n);
        for (int i = 0; i < n; ++i) {
            cin >> mapa[i];
        }
        cout << illes(mapa) << endl;
    }
}
