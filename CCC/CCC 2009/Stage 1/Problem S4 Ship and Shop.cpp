#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define MAXD 2*(int)1e9
using namespace std;

vector< pair<int,int> > adj[5000];
vector< pair<int,int> > town;
vector<int> dist(5000,11000);
vector<bool> v(5000,false);
int N,T,K,D,best = MAXD;

int dijkstra(){
    priority_queue< pair<int, int> > pq;
    pq.push( make_pair(0,D));
    while(!pq.empty()){
        int d = - (pq.top().first);
        int n = pq.top().second;
        pq.pop();

        if(v[n])continue;
        else    v[n] = true;

        if(dist[n] > d)      dist[n] = d;
        else if(dist[n] < d) continue;
        if(n == N)break;

        for(int j = 0;j < adj[n].size();++j)
            if(!v[adj[n][j].first])pq.push(make_pair( -(d + adj[n][j].second), adj[n][j].first));
    }
    for(int i = 0;i < K;++i){
        if(dist[town[i].first]+town[i].second < best)
            best = dist[town[i].first]+town[i].second;
    }
    return best == MAXD ? 0:best;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&T);
    int a,b,c;
    for(int i = 0;i < T;++i){
        scanf("%d%d%d",&a,&b,&c);
        adj[a-1].push_back( make_pair(b-1,c) );
        adj[b-1].push_back( make_pair(a-1,c) );
    }
    scanf("%d",&K);
    for(int i = 0;i < K;++i){
        scanf("%d%d",&a,&b);
        town.push_back( make_pair(a-1,b));
    }
    scanf("%d",&D);D--;
    printf("%d\n",dijkstra());
    return 0;
}
