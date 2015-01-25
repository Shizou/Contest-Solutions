#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#define MAXN 16
#define BES 0
#define ELS 1
#define pb push_back
#define mp make_pair
using namespace std;

int N,M,cost = 1<<23;
int adj[MAXN][MAXN][2];


void rec(int f1, int c1, int f2, int c2){
    if(f1 == N && f2 == N && c1 == c2)
        cost = min(cost,c1);
    if(f1!=N && f2!=N){// move both cows
        for(int i = f1; i <= N;i++)
            for(int j = f2; j <= N;j++)
                if(adj[f1][i][BES] != 0 && adj[f2][j][ELS] != 0)
                    if(c1 + adj[f1][i][BES] < cost && c2 + adj[f2][j][ELS] < cost)
                        rec(i,c1+adj[f1][i][BES],j,c2+adj[f2][j][ELS]);
    }
    else if(f1!=N){// move Bessie
        for(int i = f1; i <= N;i++)
            if(adj[f1][i][BES] != 0)
                if(c1 + adj[f1][i][BES] < cost)
                    rec(i,c1+adj[f1][i][BES],f2,c2);
    }
    else if(f2!=N){
        for(int i = f2; i <= N;i++)
            if(adj[f2][i][ELS] != 0)
                if(c2 + adj[f2][i][ELS] < cost)
                    rec(f1,c1,i,c2+adj[f2][i][ELS]);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    freopen("meeting.in","r",stdin);
    freopen("meeting.out","w",stdout);
    scanf("%d%d",&N,&M);N--,M--;
    for(int i = 0,a,b,c,d; i <= M;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a--,b--;
        adj[a][b][BES] = c;
        adj[a][b][ELS] = d;
    }
    rec(0,0,0,0);
    if(cost != 1<<23)
        printf("%d\n",cost);
    else
        printf("IMPOSSIBLE\n");
    return 0;
}
