#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXDP = (int)1e4+1;
int T,N,SPS,idx;
int dp[MAXDP];

bool is_prime(int x){
   if(x < 2 || x%2 == 0)return false;
   for(int i = 3;i <= sqrt(x);i+=2)
       if(x%i == 0)return false;
   return true;
}
int main(){
    scanf("%d",&T);
    while(T--){
      scanf("%d",&N);
      memset(dp,0,sizeof(dp));
      for(int i = 1;i <= N;++i){
          scanf("%d",&dp[i]);
          dp[i]+=dp[i-1];
      }
      SPS = N+1,idx = -1;
      for(int i = 2;i <= N;++i){
          for(int j = 1;i-j >= 0 && j < SPS;++j){
              if(is_prime(dp[i]-dp[i-j-1]) ){
                  if(j+1 < SPS){
                     SPS = j+1;
                     idx = i-j;
                  }
              }
          }
      }
      if(idx == -1)
         printf("This sequence is anti-primed.\n");
      else{
         printf("Shortest primed subsequence is length %d: ",SPS);
         for(int i = idx;SPS--;++i)
            printf("%d ",dp[i]-dp[i-1]);
         printf("\n");
      }

    }
    return 0;
}