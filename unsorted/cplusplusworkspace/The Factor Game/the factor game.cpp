#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 44723;
int N;
int dp[MAXN][2];

int main(){
    dp[1][0] = dp[1][1] = 0;
    for(int i = 1;i <= MAXN;++i){
      for(int j = i+i;j <= MAXN;j+=i){
          if(dp[j][0] < dp[i][0]+1)
              dp[j][1] = dp[j][0], dp[j][0] = dp[i][0]+1;
          else if(dp[j][1] < dp[i][0]+1)
              dp[j][1] = dp[i][0]+1;
      }
    }
}