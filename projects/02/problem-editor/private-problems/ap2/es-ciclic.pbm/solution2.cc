#include <iostream> 
#include <vector> 

using namespace std;

typedef vector<bool> VB;
typedef vector<int>  VI;
typedef vector<VI>  VVI;
  
bool can_reach_cycle_from(const VVI& g, int v, VB& vis, VB& sta) { 
  // Mark the current node as visited and part of recursion stack.
  vis[v] = sta[v] = true; 
  
  for(int u : g[v])  
    if (sta[u] or (not vis[u] and can_reach_cycle_from(g, u, vis, sta)))
      return true; 

  sta[v] = false;  // Remove the vertex from recursion stack.
  return false; 
} 

  
bool is_cyclic(const VVI& g) { 
  int n = g.size();
  VB vis(n, false);
  VB sta(n, false);
  
  for(int v = 0; v < n; v++) 
    if (not vis[v] and can_reach_cycle_from(g, v, vis, sta)) 
      return true; 
  
  return false; 
} 

  
int main() {
  int n;
  while (cin >> n) {
    VVI g(n);
    int m;
    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
    }
    if (is_cyclic(g)) cout << "yes" << endl;
    else              cout << "no"  << endl;
  }
} 
