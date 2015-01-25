#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#define MAXN 500
#define MAXINT 1<<25
#define pb push_back
#define mp make_pair
using namespace std;

int A,B,N,cost = MAXINT;
int rcost[MAXN], present[MAXN][10001];
vector<int>adj[MAXN];

int main(){
    scanf("%d%d%d",&A,&B,&N);

    for(int i = 0; i < MAXN;i++)
        for(int j = 0; j < 10001;j++)
                present[i][j] = -1;

    for(int i = 0,n = 0; i < N;i++){
        scanf("%d%d",&rcost[i],&n);
        for(int j = 0, ct = 0; j < n;j++){
            scanf("%d",&ct);
            adj[i].pb(ct);
            present[i][ct] = j;
        }
    }
    // try one route
    for(int i = 0; i < N;i++){
        if(present[i][A] != -1 && present[i][B] != -1){
            if(present[i][A] < present[i][B])
                cost = min(cost,rcost[i]);
        }
    }
    // try two routes
    for(int i = 0; i < N;i++){
        if(present[i][A] != -1){
            for(int j = 0; j < adj[i].size();j++){
                for(int k = 0; k < N;k++){
                    if(i == k)continue;// do not use the same route
                    if( present[k][adj[i][j]] != -1 && present[k][B] != -1){
                        if(present[k][adj[i][j]] <= present[k][B]){
                            cost = min(cost,rcost[i]+rcost[k]);
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", (cost == MAXINT) ? -1:cost);
    return 0;
}
