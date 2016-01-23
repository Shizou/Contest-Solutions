#include<cstdio>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int C,R,D,x,y,w2;
vector< pair< int, int > > adj[10005];
set< int > cities;
vector< bool> v(10005,0);
vector<int> dist(10005,-1);

struct edge{
    int w, sn, en;
    bool operator < (const edge& rhs) const{
        return w < rhs.w;
    }
};
int prim(){
    priority_queue< edge > pq;
    for(int i = 0; i < adj[0].size();i++)
        pq.push( (edge){adj[0][i].second, 0, adj[0][i].first});
    v[0] = 1;
    int MSTNodes = 0, MINWeight = 100000;
    while(MSTNodes < cities.size() && !pq.empty()){
        int w = pq.top().w;
        int sn = pq.top().sn;
        int en = pq.top().en;
        pq.pop();

        if(!v[en]){
            v[en] = true;
            if(cities.find(en) != cities.end())
                MSTNodes++;

            if(w < MINWeight)MINWeight = w;

            for(int i = 0; i < adj[en].size();i++){
                      if( dist[ adj[en][i].first ] < adj[en][i].second ){
                        dist[ adj[en][i].first ] = adj[en][i].second;
                        pq.push( (edge){adj[en][i].second, en, adj[en][i].first});
                      }
            }
        }
    }
    return MINWeight;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&C,&R,&D);
    for(int i = 0; i < R;i++){
        scanf("%d%d%d",&x,&y,&w2);
        adj[x-1].push_back( make_pair(y-1,w2));
        adj[y-1].push_back( make_pair(x-1,w2));
    }
    for(int i = 0; i < D;i++){
        scanf("%d",&x);
        cities.insert(x-1);
    }
    printf("%d\n", prim());
}
