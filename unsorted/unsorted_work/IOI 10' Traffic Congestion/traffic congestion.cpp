#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN (int)1e6
using namespace std;

int N,P[MAXN],PP[MAXN];
vector<int> adj[MAXN];

void rec(int n){
    if(PP[n] == 0){
        for(int i = 0; i < adj[n].size;i++){
            if(PP[adj[n][i]] != 0){
                PP[n]+= PP[adj[n][i]];
                PP[n]+= P[adj[n][i]];
            }
            else{
                rec(adj[n][i]);
                PP[n]+=PP[adj[n][i]];
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d",&P[i]);
    }
    for(int i = 0,a,b; i < N-1;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
    }

    return 0;
}
