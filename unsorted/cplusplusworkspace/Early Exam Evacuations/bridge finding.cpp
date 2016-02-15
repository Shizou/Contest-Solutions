#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;


const int MAXN = (int)1e5;
int N,M,cnt;
int num[MAXN],low[MAXN];
vector<int>adj[MAXN];
vector< pair<int,int> > E;



void DFS(int u, int a,int v = 0) {
    low[u] = num[u] = ++cnt;
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

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    memset(num,-1,sizeof num);
    memset(low,-1,sizeof low);
    for(int i = 0,a,b;i < N;i++){
        scanf("%d%d",&a,&b);a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int u = 0;u < N;u++)
        if(num[u] == -1)
            DFS(u,-1);
    cnt = 0;
    for(int i = 0;i < (int)E.size();i++){
        printf("%d->%d\n",E[i].first,E[i].second);
    }
    return 0;
}