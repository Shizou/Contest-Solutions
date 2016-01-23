#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N,M,A,B,L,bd,wd = 0;
bool first = true;
int adj[250][250] = {0};
vector< pair<int,int> > bp;
vector< int > dist(250, 250000000);
vector< bool > v(250, 0);

struct state{
    int d,n;
    vector< pair<int,int> > p;
    bool operator < (const state& rhs) const {
        return d > rhs.d;
	}
};

int dijkstra(){
    priority_queue< state> pq;
    pq.push( (state){0,0, vector< pair<int,int> >()} );
    while(!pq.empty()){
        int d = pq.top().d;
        int n = pq.top().n;
        vector< pair<int,int> > p = pq.top().p;
        pq.pop();
        if(v[n])continue;
        v[n] = true;
        if(n == N-1){
            if(first)bp = p;
            first = false;
            return d;
        }
        for(int i = 0;i < 250;i++){
            int n2 = i;
            int d2 = adj[n][i];
            if(d2 == 0)continue;
            if(d+d2 <= dist[n2]){
                dist[n2] = d+d2;
                p.push_back(make_pair(n,n2));
                pq.push( (state){ dist[n2], n2, p });
                p.erase(p.begin() + p.size());
            }

        }
    }
    return 0;
}
void r(){ for(int i = 0;i < 250;i++){v[i] = 0; dist[i] = 250000000;} }

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M;i++){
        scanf("%d%d%d",&A,&B,&L);
        adj[A-1][B-1] = L;
        adj[B-1][A-1] = L;
    }
    bd = dijkstra();
    for(int i = 0;i < bp.size();i++){
        r();
        adj[ bp[i].first ][ bp[i].second ] *= 2;
        adj[ bp[i].second ][ bp[i].first ] *= 2;
        int pd = dijkstra();
        if(pd - bd > wd)wd = pd - bd;
        adj[ bp[i].first ][ bp[i].second ] /= 2;
        adj[ bp[i].second ][ bp[i].first ] /= 2;
    }
    printf("%d\n",wd);
    //fclose(stdin);
}

