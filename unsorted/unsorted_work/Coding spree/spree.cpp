#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int p,t;
int v[1001],w[1001];
int main(){
    scanf("%d%d",&p,&t);
    for(int i = 1;i < p+1;i++)scanf("%d%d",&v[i],&w[i]);
    int dp[p+1][t+1];
    for(int y = 0;y <= t;y++) dp[0][y] = 0;
    for(int x = 0;x <= p;x++) dp[x][0] = 0;
    for(int x = 1;x <= p;x++){
        for(int y = 0;y <= t;y++){
            if(w[x] <= y)dp[x][y] = max( dp[x-1][y], v[x] + dp[x-1][ (y-w[x]) ] );
            else         dp[x][y] = dp[x-1][y];
        }
    }
    printf("%d\n",dp[p][t]);
    return 0;
}
