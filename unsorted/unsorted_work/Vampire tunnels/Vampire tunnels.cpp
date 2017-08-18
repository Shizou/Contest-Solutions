#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;


vector< pair<int,pair<int,int> > > adj[1600];
vector< pair<int,int> > dist(1600, make_pair(2000000000,-1));
vector< bool > v(1600,false);

int S,N,E;
int s,t,d,u;

struct state{
    int n, d, sl;

    bool operator < (const state& rhs) const {
        return (d == rhs.d) ? (sl < rhs.sl):(d > rhs.d);
	}
};
int spfa(){
    queue< state > q;
    q.push((state){0,0,S});
    while(!q.empty()){
        int n = q.front().n;
        int d = q.front().d;
        int sl = q.front().sl;
        q.pop();
      //  printf("%d[D: %d, SL : %d]\n",n,d,sl);
        for(int i = 0; i < adj[n].size();i++){
            int d2 = adj[n][i].second.first;
            if(adj[n][i].second.second == 1){
                if(sl - d2 >= 0){
                    if(dist[adj[n][i].first].first > d+d2){
                        dist[adj[n][i].first].first = d+d2;
                        q.push( (state){ adj[n][i].first, dist[adj[n][i].first].first, sl-d2});
                     //   printf("    %d[D: %d, SL : %d]\n",adj[n][i].first,dist[adj[n][i].first].first, sl-d2);
                        if(dist[adj[n][i].first].second < sl-d2){
                            dist[adj[n][i].first].second = sl-d2;
                        }
                    }
                    else if(dist[adj[n][i].first].first == d+d2){
                        if(dist[adj[n][i].first].second <= sl-d2){
                            dist[adj[n][i].first].first = d+d2;
                            dist[adj[n][i].first].second = sl-d2;
                            q.push( (state){ adj[n][i].first, dist[adj[n][i].first].first, sl-d2});
                        }
                    }
                }
            }
            else{
                if(dist[adj[n][i].first].first > d+d2){
                        dist[adj[n][i].first].first = d+d2;
                        q.push( (state){adj[n][i].first, dist[adj[n][i].first].first, sl});
                   //     printf("    %d[D: %d, SL : %d]\n",adj[n][i].first, dist[adj[n][i].first].first, sl);
                        if(dist[adj[n][i].first].second < sl){
                            dist[adj[n][i].first].second = sl;
                        }
                }
                else if(dist[adj[n][i].first].first == d+d2){
                        if(dist[adj[n][i].first].second <= sl){
                            dist[adj[n][i].first].first = d+d2;
                            dist[adj[n][i].first].second = sl;
                            q.push( (state){ adj[n][i].first, dist[adj[n][i].first].first, sl});
                        }
                    }
            }
        }
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&S,&N,&E);
    for(int i = 0; i < E;i++){
        scanf("%d%d%d%d",&s,&t,&d,&u);
        adj[s].push_back( make_pair(t, make_pair(d,u)));
        adj[t].push_back( make_pair(s, make_pair(d,u)));
    }
    spfa();
    printf("%d\n", (dist[N-1].first == 2000000000) ? -1:dist[N-1].first);
    //printf("%d\n",dijkstra());
    //fclose(stdin);
}
