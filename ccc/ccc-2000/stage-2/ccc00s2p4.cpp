#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N,W,P;
int a,b,c;
vector< pair<int,int> > adj[500];
vector< bool > v(500,false);
vector< int > dist(500,1<<23);

int dijkstra(int sn,int en){
    priority_queue< pair<int,int> > pq;
    pq.push( make_pair(0,sn));
    while(!pq.empty()){
        int d = -(pq.top().first);
        int n = pq.top().second;
        pq.pop();

        if(v[n])continue;
        v[n] = true;

        if(dist[n] > d)dist[n] = d;
        else if(dist[n] < d)continue;

        if(n == en)return d;

        for(int i = 0; i < adj[n].size();i++)
            pq.push( make_pair(-(d + adj[n][i].second), adj[n][i].first));
    }
    return -1;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&N,&W,&P);
    for(int i = 0;i < W;i++){
       scanf("%d%d%d",&a,&b,&c);
       adj[a-1].push_back( make_pair(b-1,c));
       adj[b-1].push_back( make_pair(a-1,c));
    }
    for(int i = 0;i < P;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",dijkstra(a-1,b-1));
        fill(v.begin(),v.end(),0);
        fill(dist.begin(),dist.end(),1<<23);
    }
}
