#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 2000,MOD = 1000000007;
int R,C,K;
long long A[N][N];
long long dp[N][N];

int main(){
    scanf("%d%d%d",&R,&C,&K);
    for(int r = 0;r < R;r++)
        for(int c = 0;c < C;c++)
            scanf("%Ld",&A[r][c]);
    dp[0][0] = 1;
    for(int r = 0;r < R;r++)
        for(int c = 0;c < C;c++)
           if(dp[r][c]!=0)
              for(int r2 = r+1;r2 < R;r2++)
                 for(int c2 = c+1;c2 < C;c2++)
                    if(A[r][c]!=A[r2][c2])
                        dp[r2][c2]+=dp[r][c]%MOD;

    printf("%Ld\n",dp[R-1][C-1]%MOD);
    return 0;
}
