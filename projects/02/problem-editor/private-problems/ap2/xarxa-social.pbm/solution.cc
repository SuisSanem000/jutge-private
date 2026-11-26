#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

using Node = int;
using Name2Node = map<string, Node>;
using Graph = vector<vector<Node>>; // adyacency list
using Pair = pair<Node, int>; // (id_node, distance)

void read_graph(Graph& g, Name2Node& dict)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        dict[name] = i;
    }
    g = Graph(n);
    for (int i = 0; i < m; ++i) {
        string from, to;
        cin >> from >> to;
        g[dict[from]].push_back(dict[to]);
    }
}

// bfs
// Pre: from exists in g; k >= 0
// Post: returns how many nodes are at distance k to node from
int at_distance_k(const Graph& g, Node from, int k)
{
    int n = g.size();
    vector<bool> enq(n, false);
    queue<Pair> q;
    q.push({ from, 0 });
    enq[from] = true;
    int count = 0;
    while (not q.empty()) {
        Pair info = q.front();
        q.pop();
        int dist = info.second; // to clarify code
        if (dist == k)
            ++count;
        else {
            Node u = info.first; // to clarify code
            for (Node v : g[u])
                if (not enq[v]) {
                    q.push({ v, dist + 1 });
                    enq[v] = true;
                }
        }
    }
    return count;
}

int main()
{
    Graph g;
    Name2Node dict;
    read_graph(g, dict);

    string name;
    int k;
    while (cin >> name >> k) {
        cout << at_distance_k(g, dict[name], k) << endl;
    }
}