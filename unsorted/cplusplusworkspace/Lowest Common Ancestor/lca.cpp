#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#define swap(x,y) x^=y^=x^=y
using namespace std;

const int MAXN = 1001,MAXLOGN = 10;
int TT,N,M,Q;
int L[MAXN],T[MAXN];
int P[MAXN][MAXLOGN];

vector<int>adj[MAXN];

void dfs(int n,int p){
    T[n] = p, L[n] = L[T[n]]+1;
    for(int i = 0;i < (int)adj[n].size();++i)
        dfs(adj[n][i],n);
}
void preprocess(){
    memset(P,-1,sizeof(P));
    for(int i = 0;i <= N;i++)
        P[i][0] = T[i];
    for(int j = 1; (1<<j) <= N;j++)
        for(int i = 0;i < N;i++)
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
}
int lca(int v,int w){
    if(L[v] < L[w])
        swap(v,w);
    int log = 1;
    for(log = 1; (1<<log) <= L[v];log++)
        log--;
    for(int i = log; i >= 0; i--)
        if(L[v] - (1 << i) >= L[w])
           v = P[v][i];
    if(v == w)
        return v;
    for(int i = log; i >= 0; i--)
        if(P[v][i] != -1 && P[v][i] != P[w][i])
           v = P[v][i], w = P[w][i];
    return T[v];
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&TT);
    while(TT--){
      scanf("%d",&N);
      for(int i = 0;i < N;++i){
          scanf("%d",&M);
          for(int j = 0,k = 0;j < M;++j){
            scanf("%d",&k);
            adj[i].push_back(k-1);
          }
      }
      dfs(0,0);
      scanf("%d",&Q);
      printf("Case %d:\n",T+1);
      for(int i = 0,v,w;i < Q;++i){
          scanf("%d%d",&v,&w);
          printf("%d\n", (lca(v-1,w-1)+1) );
      }
      for(int i = 1;i <= N;++i)
          adj[i].clear();
    }
    return 0;
}