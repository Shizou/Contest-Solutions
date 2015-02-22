#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 2*(int)1e3,MAXK = 201, INF = 0x3F3F3F3F;
int K,N,M,A,B;
int dist[MAXN][MAXK];
vector< pair<int,pair<int,int> > >adj[MAXN];// node, distance, hull damage


int dijkstra(){
    priority_queue< pair<int,pair<int,int> > >pq;// distance, hull damage, node
    pq.push(mp(0,mp(-K,A)));
    while(!pq.empty()){
        int d = -pq.top().first;
        int k = -pq.top().second.first;
        int n = pq.top().second.second;
        pq.pop();
        for(int i = 0;i < adj[n].size();i++){
            int nt = adj[n][i].first;
            int w  = adj[n][i].second.first;
            int we = k-adj[n][i].second.second;
            if(we > 0 && dist[nt][we] > d + w){
                dist[nt][we] = d + w;
                pq.push(mp(-dist[nt][we],mp(-we,nt)));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= K;i++)
        ans = min(ans,dist[B][i]);
    return ans == INF ? -1:ans;
}


int main(){
    memset(dist,INF,sizeof dist);
    scanf("%d%d%d",&K,&N,&M);
    for(int i = 0,a,b,t,h;i<M;i++){
        scanf("%d%d%d%d",&a,&b,&t,&h);a--,b--;
        adj[a].pb(mp(b,mp(t,h)));
        adj[b].pb(mp(a,mp(t,h)));
    }
    scanf("%d%d",&A,&B);A--,B--;
    printf("%d\n",dijkstra());
    return 0;
}

