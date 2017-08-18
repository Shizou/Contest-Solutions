#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodes, edges, x, y;
vector<int> adj[1000005]; /* array of vectors */

bool BFS(int a, int b) { /* if there’s a path from a to b, returns true */
  bool V[1000005];
  for (int i = 1; i <= nodes; i++) V[i] = false;
  queue<int> Q;
  Q.push(a);
  while (!Q.empty()) {
    int n = Q.front(); /* get the node */
    Q.pop();
    if (V[n]) continue; /* already visited*/
    if (n == b) return true; /* FOUND THE OTHER NODE :D */
    V[n] = true; /* flag as visited */

    for (int i = 0; i < adj[n].size(); i++) { /* for all the edges that n goes to */
      Q.push(adj[n][i]);
    }
  }
  return false; /* not found :*(  */
}

int main() {
 scanf("%d%d", &nodes, &edges); /* read # of nodes/edges */
 for (int i = 0; i < edges; i++) {
   scanf("%d%d", &x, &y); /* read in x and y */
   adj[x].push_back(y);  /* add the edge */
 }
 scanf("%d%d", &x, &y); /* read in the query for whether x is taller than y */

 bool xtaller = BFS(x, y);
 bool ytaller = BFS(y, x);

 if (xtaller) cout << "yes" << endl;
 else if (ytaller) cout << "no" << endl;
 else cout << "unknown" << endl;

 return 0;
}
