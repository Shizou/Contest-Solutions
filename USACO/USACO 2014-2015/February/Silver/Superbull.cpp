#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 2000;
long long N;
int arr[MAXN];
int parent[MAXN];
vector< pair<long long, pair<int,int> > >edges;

int find(int x){
    if(parent[x]!=x)parent[x] = find(parent[x]);
    return parent[x];
}
void merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main(){
    //freopen("superbull.in","r",stdin);
    //freopen("superbull.out","w",stdout);
	scanf("%d",&N);
	for(int i = 0;i < N;i++){
		scanf("%d",&arr[i]);
        parent[i] = i;
	}
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			if(i == j)continue;
            edges.pb(mp(arr[i]^arr[j],mp(i,j)));
		}
	}
	long long ans = 0,n = 0;
	sort(edges.begin(),edges.end(), greater< pair<long long, pair<int,int> > >());
    for(int i = 0;i < edges.size();i++){
        int a = find(edges[i].second.first);
        int b = find(edges[i].second.second);
        if(a!=b){
            n++;
            merge(a,b);
            ans+=edges[i].first;
        }
    }
    printf("%Ld\n",ans);
	return 0;
}

