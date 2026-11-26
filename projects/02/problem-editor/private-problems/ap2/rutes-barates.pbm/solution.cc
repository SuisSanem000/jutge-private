#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

typedef int vertex;

struct edge {
    vertex _target;
    int _weight;

    edge(vertex v, int w)
        : _target(v)
        , _weight(w) {};
    vertex target() const { return _target; }
    int weight() const { return _weight; }
};

typedef vector<vector<edge>> edge_weighted_graph;

struct vertex_edge_weighted_graph {
    int num_vertices; // number of vertices
    int num_edges;
    edge_weighted_graph succ; // adjancecy list
    vector<int> weight; // vertex weights
    void read(istream& is)
    {
        int n, m;
        is >> n >> m;
        num_vertices = n;
        num_edges = m;
        weight = vector<int>(n);
        succ = edge_weighted_graph(n);
        for (vertex u = 0; u < n; ++u)
            is >> weight[u];
        int u, v;
        int w;
        for (int i = 0; i < m; ++i) {
            is >> u >> v >> w;
            succ[u].push_back(edge(v, w));
            succ[v].push_back(edge(u, w));
        }
    }
    void print(ostream& os) const
    {
        os << num_vertices << " " << num_edges << endl;
        for (vertex u = 0; u < num_vertices; ++u)
            os << ((u == 0) ? "" : " ") << weight[u];
        os << endl;
        bool first = true;
        for (vertex u = 0; u < num_vertices; ++u) {
            for (edge e : succ[u]) {
                if (first)
                    first = false;
                else
                    os << " ";
                os << u << " " << e.target() << " " << e.weight();
            }
            os << endl;
        }
    }
};

istream& operator>>(istream& is, vertex_edge_weighted_graph& G)
{
    G.read(is);
    return is;
}

ostream& operator<<(ostream& os, const vertex_edge_weighted_graph& G)
{
    G.print(os);
    return os;
}

typedef pair<int, vertex> pq_item; // pair <distance,vertex>

// Pre: a weighted graph G = <V,E> with positive weight on edges and vertices, V = {0,...,n-1}
// Post: Gp = <Vp, Ep>; for each vertex u in G, we have two vertices u and u+n;
//       for every edge e=(u,v,w(e)) in E we have an edge (u+n,v,w(e)) in Ep
//       moreover for every vertex u with cost w(u) we have an edge (u,u+n,w(u)) in Ep
void transform(const vertex_edge_weighted_graph& G, edge_weighted_graph& Gp)
{
    int n = G.num_vertices;
    Gp = edge_weighted_graph(2 * n); // Gp has twice as many vertices as G
    for (vertex u = 0; u < n; ++u) {
        Gp[u].push_back(edge(u + n, G.weight[u]));
        Gp[u + n].push_back(edge(u, G.weight[u]));
        for (edge e : G.succ[u])
            Gp[u + n].push_back(e);
    }
}

// Pre: a weighted graph G = <V,E> with positive weight on edges, V = {0,...,n-1}, s,t in V
// Post: returns the cost of the shortest path in G between s and t, or -1 if there is no path from s to t
// The problem is solved using Dijkstra's algorithm for single-source-shortest paths, but the main
// loop is exited as soon as the candidate vertex is t

int shortest_path(const edge_weighted_graph& G, vertex s, vertex t)
{
    const int INF = numeric_limits<int>::max();
    vector<int> D(G.size(), INF);
    vector<bool> visited(G.size(), false);
    priority_queue<pq_item, vector<pq_item>, greater<pq_item>> candidates;

    candidates.push(make_pair(0.0, s));
    D[s] = 0.0;
    bool finished = false;
    while (not finished and not candidates.empty()) {
        vertex u = candidates.top().second;
        candidates.pop();
        if (not visited[u]) {
            visited[u] = true;
            finished = (u == t);
            for (edge e : G[u]) {
                vertex v = e.target();
                int d = D[u] + e.weight();
                if (d < D[v]) {
                    D[v] = d;
                    candidates.push(make_pair(d, v));
                }
            }
        }
    }
    if (finished)
        return D[t];
    else
        return -1.0;
}

int main()
{
    vertex_edge_weighted_graph G;
    edge_weighted_graph Gp;
    cin >> G;
    transform(G, Gp);
    vertex A, B;
    int n = G.num_vertices;
    while (cin >> A >> B) {
        int cost = 0.0;
        if (A != B)
            cost = shortest_path(Gp, A + n, B);
        cout << "c(" << A << "," << B << ") = ";
        if (cost < 0)
            cout << "+oo" << endl;
        else
            cout << cost << endl;
    }
}
