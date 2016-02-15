#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N,M,S,T;
int u,v,x;

vector< pair< int, long long> >adj[100000];
vector< bool > vist(100000,0);
vector< long long> dist(100000,1<<24);

struct path{
    int n;
    long long w;
    vector<int>pv;
    bool operator < (const path& rhs) const{
        return w < rhs.w;
    }
};
long long dijkstra(){
	priority_queue< path > pq;
	vector<int>nil;
	nil.push_back(S);
	pq.push( (path){S,0,nil});
	while(!pq.empty()){
		int n = pq.top().n;
		long long w = pq.top().w;
		vector<int>pv = pq.top().pv;
		pq.pop();
		if(vist[n])continue;
		vist[n] = true;
		if(dist[n] < w)
			continue;
		else
			dist[n] = w;
       // cout << n << endl;
        pv.push_back(n+1);
		if(n == T-1){
			return w;
		}
		for(int i = 0;i < adj[n].size();i++){
			pq.push( (path){adj[n][i].first, adj[n][i].second, pv} );
		}
	}
	return 0;
}
int main() {
    freopen("input.txt","r",stdin);
	scanf("%d%d",&N,&M);
	cout << M << endl;
	for(int i = 0; i < M;i++){
		scanf("%d%d%d",&u,&v,&x);
		adj[u-1].push_back(make_pair(v-1,1 << x));
	}
	scanf("%d%d",&S,&T);
	long long ans = dijkstra();
	cout << ans << endl;
	printf("%ll\n", (ans != 0)? (ans%1000000007): -1);
	return 0;
}
