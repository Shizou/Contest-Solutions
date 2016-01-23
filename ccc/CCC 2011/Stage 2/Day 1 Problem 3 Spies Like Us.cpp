#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
using namespace std;

const int MAXN = 2000;
int N,M,K;
int  cnt[MAXN][MAXN];
bool mtx[MAXN][MAXN];
vector<int>adj[MAXN];

int main(){
    //freopen("Input/spies.4.in","r",stdin);
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 0,a,b;i < K;i++){
        scanf("%d%d",&a,&b);
        adj[--a].pb(--b);
        mtx[a][b] = true;
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < (int)adj[i].size();j++){
            for(int k = 0;k < N;k++){
                if(i!=k && mtx[k][adj[i][j]]){
                   cnt[i][k]++;
                   if(cnt[i][k] > 1){
                      printf("NO\n");
                      return 0;
                   }
                }
            }
        }
    }
    printf("YES\n");
    return 0;
}

