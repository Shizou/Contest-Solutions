#include<bits/stdc++.h>
#define DB 0
#define MAXN 10005
#define inf 0x3f3f3f3f
#define ms(a,b) memset( (a), (b), sizeof( (a) ))
#define len(x) (int)(x).size()
using namespace std;

int N,M,Q,S;
int dist[MAXN];
vector< pair<int,int> >adj[MAXN];

void dijkstra(){
     priority_queue< pair<int,int> >q;
     q.push(make_pair(0,S));
     dist[S] = 0;
     while(!q.empty()){
           pair<int,int> p = q.top();
           int w = -p.first, n = p.second;
           q.pop();
           for(int i = 0;i < len(adj[n]);i++){
               int nt = adj[n][i].first;
               int ww = adj[n][i].second;
               if(dist[nt] > w+ww){
                  dist[nt] = w+ww;
                  q.push(make_pair(-dist[nt],nt));
               }
           }
     }
}


int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif

    while(cin >> N >> M >> Q >> S && !(N == 0 && M == 0 && Q == 0 && S == 0) ){
          for(int i = 0,u,v,w;i < M;i++){
              cin >> u >> v >> w;
              adj[u].push_back(make_pair(v,w));
              //adj[v].push_back(make_pair(u,w));
          }
          ms(dist,inf);
          dijkstra();
          for(int i = 0,t;i < Q;i++){
              cin >> t;
              if(dist[t] == inf)
                 cout << "Impossible" << endl;
              else
                 cout << dist[t] << endl;
          }
          for(int i = 0;i < N;i++)
              adj[i].clear();
          cout << endl;
    }
    return 0;
}