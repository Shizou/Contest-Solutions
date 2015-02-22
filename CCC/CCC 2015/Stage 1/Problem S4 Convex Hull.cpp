#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 2001,MAXK = 201, INF = 0x3f3f3f3f;
int K,N,M,A,B;
int dist[MAXN][MAXK];
vector< pair<int,pair<int,int> > >adj[MAXN];// node, distance, hull damage

int dijkstra(){
    // Main idea is to perfom dijkstra's algorithm on the graph but instead of using
    // a one dimensional distance array that holds the minimum distance to get to an
    // island we use a 2D distance array that holds the minimum distance to
    // get to an island under a certain damage the hull has received.

    // Just an fyi in c++ the priority queue is a max heap so to circumvent this we
    // negatize the weights and hull damage so that the priority queue still prioritizez
    // what we want. I.e. -1 > -7
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
            int dt = k-adj[n][i].second.second;
            if(dt > 0 && dist[nt][dt] > d+w){
                dist[nt][dt] = d+w;
                pq.push(mp(-dist[nt][dt],mp(-dt,nt)));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= K;i++)
        ans = min(ans,dist[B][i]);
    return ans == INF ? -1:ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    memset(dist,INF,sizeof(dist));
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

