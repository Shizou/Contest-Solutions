#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define UG 0
#define OG 1
using namespace std;

const int MAXN = 1601, MAXSL = 3601,INF = 0x3F3F3F3F;
int S,N,E,ans = INF,tans;
vector< pair<int,pair<int,int> > > adj[MAXN]; // city, distance, sunlight
int dist[MAXN][MAXSL];

void dijkstra(){
    priority_queue< pair<int,pair<int,int> > >pq;
    pq.push(mp(0,mp(0,0)));
    while(!pq.empty()){
        int d = -(pq.top().first);
        int sl = -(pq.top().second.first);
        int n = pq.top().second.second;
        pq.pop();
        //printf("%d[%d %d]\n",n,d,sl);
        if(n == N)break;
        for(int i = 0;i < adj[n].size();++i){
            if(adj[n][i].second.second == UG){
                if(dist[adj[n][i].first][sl] > d+adj[n][i].second.first){
                    dist[adj[n][i].first][sl] = d+adj[n][i].second.first;
                    pq.push(mp(-(d+adj[n][i].second.first),mp(-(sl),adj[n][i].first)));
                }
            }
            else if(adj[n][i].second.second == OG){
                if(sl + adj[n][i].second.first <= S){
                    if(dist[adj[n][i].first][sl] > d+adj[n][i].second.first){
                        dist[adj[n][i].first][sl] = d + adj[n][i].second.first;
                        pq.push(mp(-(d + adj[n][i].second.first),mp(-(sl + adj[n][i].second.first),adj[n][i].first)));
                    }
                }
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    memset(dist,INF,sizeof(dist));
    scanf("%d%d%d",&S,&N,&E);N--,E--;
    for(int i = 0,s,t,d,u; i <= E;++i){
        scanf("%d%d%d%d",&s,&t,&d,&u);
        adj[s].pb(mp(t,mp(d,u)));
        adj[t].pb(mp(s,mp(d,u)));
    }
    dijkstra();
    for(int i = 0; i <= S;++i)
        ans = min(ans,dist[N][i]);
    if(ans == INF)
        ans = -1;
    printf("%d\n",ans);
    return 0;
}
