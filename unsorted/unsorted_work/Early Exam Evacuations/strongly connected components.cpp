#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 101;
int nodes, edges, u, v, counter, num[MAX_N], low[MAX_N];
bool visit[MAX_N] = {0};
vector<int> adj[MAX_N];


void DFS(int u, int a,int v = 0) {
    low[u] = num[u] = ++counter;
    for (int j = 0; j < adj[u].size(); j++) {
          v = adj[u][j];
          if (num[v] == -1) {
              DFS(v, u);
              low[u] = min(low[u], low[v]);
          }else if (v != a)
              low[u] = min(low[u], num[v]);
    }
    for (int j = 0; j < adj[u].size(); j++){
         v = adj[u][j];
         if (low[v] > num[u])
             cout << u+1 << "-" << v+1 << " is a bridge\n";
    }
}
int main() {
  freopen("input.txt","r",stdin);
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
      cin >> u >> v; u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  memset(num,-1,sizeof(num));
  memset(low,-1,sizeof(low));
  memset(visit,false,sizeof(visit));
  counter = 0;
  for (int i = 0; i < nodes; i++)
       if (num[i] == -1) DFS(i, -1);
return 0;
}