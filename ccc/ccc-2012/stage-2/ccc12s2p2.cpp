#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 2*(int)1e4 + 5, INF = 0x3F3F3F3F;
int N,M,dist[MAXN][2];
vector< pair<int,int> > adj[MAXN];// city, weight

void spfa(){
    queue< pair<int,int> >q;
    q.push(mp(0,1));
    while(!q.empty()){
        int n = q.front().second;
        int d = q.front().first;
        q.pop();
        for(int i = 0; i < adj[n].size();++i){
            if(dist[adj[n][i].first][0] > d + adj[n][i].second){
                dist[adj[n][i].first][1] = dist[adj[n][i].first][0];
                dist[adj[n][i].first][0] = d+adj[n][i].second;
                q.push(mp(d+adj[n][i].second,adj[n][i].first));
            }
            else if(dist[adj[n][i].first][0] != d + adj[n][i].second && dist[adj[n][i].first][1] > d + adj[n][i].second){
                dist[adj[n][i].first][1] = d+adj[n][i].second;
                q.push(mp(d+adj[n][i].second,adj[n][i].first));
            }
        }
    }
}
int main(){
    memset(dist,INF,sizeof(dist));
    scanf("%d%d",&N,&M);
    for(int i = 0,a,b,l; i < M;++i){
        scanf("%d%d%d",&a,&b,&l);
        adj[a].pb(mp(b,l));
    }
    spfa();
    printf("%d\n",(dist[N][1] != INF) ? dist[N][1]:-1);
    return 0;
}

