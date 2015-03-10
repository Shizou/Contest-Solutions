#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int D = 250,MOD = (int)1e9+7,A = 0,B = 1;
int T,N,M;
int fx[D][2];
int dp[D][D];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < N;i++)
            scanf("%d%d",&fx[i][A],&fx[i][B]);
        for(int i = fx[0][A];i <= fx[0][B];i++)
            dp[0][M-i]++;
        for(int i = 0;i < N-1;i++){
            for(int j = 0;j <= M;j++){
                if(dp[i][j]==0)continue;
                for(int k = fx[i+1][A];k <= fx[i+1][B];k++){
                    if(j-k >= 0){
                        dp[i+1][j-k]+=dp[i][j];
                        dp[i+1][j-k]%=MOD;
                    }
                }
            }
        }
        printf("%d\n",dp[N-1][0]%MOD);
    }
    return 0;
}

