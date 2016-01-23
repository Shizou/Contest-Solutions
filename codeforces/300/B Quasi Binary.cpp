#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int MAXN = (int)1e6+5,inf = 0x3f3f3f3f;
int N,T = MAXN;
int dp[MAXN],trace[MAXN];
vector<int>qq;

bool quasi(int x){
  while(x > 0){
    if(x%10 != 0 && x%10 != 1)return false;
    x/=10;
  }
  return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    memset(dp,inf,sizeof(dp));
    for(int i = 0;i < MAXN;i++){
        if(quasi(i)){
          qq.pb(i);
          dp[i] = 1;
        }
    }
    for(int i = 0;i < MAXN;i++){
        if(quasi(i))continue;
        for(int j = 0;j < (int)qq.size();j++){
            if(i-qq[j] >= 0 && dp[i] > dp[i-qq[j]]){
                dp[i] = dp[i-qq[j]]+1;
                trace[i] = i-qq[j];
            }
        }
    }
    printf("%d\n",dp[N]);
    if(quasi(N))
        printf("%d\n",N);
    else{
        while(N > 0){
            for(int i = 0;i < (int)qq.size();i++){
                if(N-qq[i] == trace[N]){
                   printf("%d ",qq[i]);
                   N-=qq[i];
                   break;
                }
            }
        }printf("\n");
    }
    return 0;
}