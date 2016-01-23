/*TLES ON LAST THREE TESTCASES*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define mp make_pair
using namespace std;

const int MAXN = 5*(int)1e6+5,INF = 0x3F3F3F3F;
int N;
vector<int>dp(MAXN,INF);

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    dp[1] = 0;
    for(int i = 1; i <= N;i++){
        for(int j = 1;j <= (int)sqrt(i);j++){
            if(i%j==0){
                if(dp[i+j] > dp[i] + i/j)
                    dp[i+j] = dp[i]+i/j;
                if(dp[i+i/j] > dp[i]+j)
                    dp[i+i/j] = dp[i]+j;
            }

        }
    }
    printf("%d\n",dp[N]);
    return 0;
}
