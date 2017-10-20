// WIP - for some reason official solution provided by vassos doesn't work :x
#include <algorithm>
#include <bitset>
#include <cctype>
#include <iostream>
#include <queue>
#include <sstream>
#include <cstring>
#include <vector>

#define MAXN 100000
#define inf 0x3f3f3f3f
#define db 0
using namespace std;

vector<pair<int,int>>adj[MAXN]; // next node, weight
int V,E;
int dist[MAXN];
int num[MAXN];

string int_to_string(int v){
    stringstream ss;
    string s;
    ss << v;
    ss >> s;
    return s;
}

void debug_state(){
    printf("dist: ");
    for(int i = 0;i < V;i++){
        printf("%s ", dist[i] == inf ? "∞" : int_to_string(dist[i]).c_str());
    }printf("\n");
    printf("num : ");
    for(int i = 0;i < V;i++){
        printf("%d ", num[i]); 
    }printf("\n");
}
void dijkstra(int s, int t){
    priority_queue< pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> >pq;
    for(int i = 0;i < V;i++){
        dist[i] = inf;
        num[i] = 0;
    }
    for(int i = 0;i < adj[s].size();i++){
        pair<int,int>edge = adj[s][i]; // node, weight
        int u = edge.first;
        int wt = edge.second;
        dist[u] = wt;
        num[u] = 1;
        pq.push(make_pair(dist[u], u));
    }
    dist[s] = 0;
    num[s] = 1; 
    if(db)debug_state();
    while(!pq.empty()){
        int d  = pq.top().first;
        int u  = pq.top().second;
        pq.pop();
        if(d > dist[u])continue;
        if(db)cout << "traversing node: " << u << " with weight: " << d << endl;
        for(auto &it: adj[u]){
            pair<int,int>edge = it; // node, weight
            int v = edge.first;
            int wt = edge.second;
            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                num[v] = num[u];
                pq.push(make_pair(dist[v], v));
            } else if(dist[v] == dist[u] + wt){
                num[v] = num[v] + num[u];
            }
        }
        if(db)debug_state();
    }
}

int main() {
    cin >> V >> E;
    for(int i = 0;i < E;i++){
        int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w));
    }
	int s,t;
    scanf("%d%d",&s,&t);
    dijkstra(s,t);
    printf("%d\n", num[t]);
    return 0;
}
