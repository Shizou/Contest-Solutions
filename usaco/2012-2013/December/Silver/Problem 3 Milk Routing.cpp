#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 505,MAXM = 505,INF = 0x3F3F3F3F;
int N,M,X,ans = INF,tans;
int dist[MAXN],cap[MAXM];
vector< pair<int, pair<int,int> > >adj[MAXN];

void spfa(int &c){
    queue< pair<int,int> >q;
    q.push(mp(0,0));
    while(!q.empty()){
        int lc = q.front().first;
        int n = q.front().second;
        q.pop();
        for(int i = 0; i < adj[n].size();i++){
            if(adj[n][i].second.second >= c){
                if(dist[adj[n][i].first] > lc + adj[n][i].second.first){
                    dist[adj[n][i].first] = lc + adj[n][i].second.first;
                    q.push(mp(dist[adj[n][i].first],adj[n][i].first));
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&X);N--,M--;
    for(int k = 0,I,J,L,C;k <= M;k++){
        scanf("%d%d%d%d",&I,&J,&L,&C);I--,J--;
        adj[I].pb(mp(J,mp(L,C)));
        adj[J].pb(mp(I,mp(L,C)));
        cap[k] = C;
    }
    for(int i = 0; i < M;i++){
        memset(dist,INF,sizeof(dist));
        spfa(cap[i]);
        ans = min(ans,dist[N] + X/cap[i]);
    }
    printf("%d\n",ans);
    return 0;
}

