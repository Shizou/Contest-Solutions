#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = (int)1e6;
int N, arr[MAXN],dp[MAXN],max_branch[MAXN];
vector<int>adj[MAXN];

int r1(int n,int p){
	int sum = arr[n], b = 0;
	for(int i = 0; i < adj[n].size();i++){
		b = 0;
		if(adj[n][i] != p){
            b = r1(adj[n][i],n);
            max_branch[n] = max(max_branch[n],b);
            sum+=b;
		}
        dp[n] = sum;
	}
	return dp[n];
}
void r2(int n, int p){
    int b = 0;
    for(int i = 0; i < adj[n].size();i++){
        b = dp[n]- dp[adj[n][i]];
        max_branch[adj[n][i]] = max(max_branch[adj[n][i]],b);
        dp[adj[n][i]]+=b;
    }
    for(int i = 0; i < adj[n].size();i++)
        if(adj[n][i] != p)r2(adj[n][i],n);
}

int main() {
    freopen("input.txt","r",stdin);
	scanf("%d",&N);
	for(int i = 0; i < N;i++)
		scanf("%d",&arr[i]);
	for(int i = 0,a,b; i < N-1;i++){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	r1(0,0);
	r2(0,0);
    int branch = 0x3F3F3F3F, cit = 0;
    for(int i = 0;i < N;i++){
        if(max_branch[i] < branch){
            branch = max_branch[i];
            cit = i;
        }
    }
	printf("%d\n",cit);
	return 0;
}

