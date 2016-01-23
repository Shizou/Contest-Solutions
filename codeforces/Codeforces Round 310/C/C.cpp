#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

const int MAXN = (int)1e5+1,inf = 0x3f3f3f3f;
int N,M,K;
int arr[MAXN];
int dp[MAXN][2];

bool done(){
   for(int i = 0;i < N;i++){
       if(arr[i] != i+1)return false;
   }
   return true;
}
int main(){
    freopen("C-input.txt","r",stdin);
    needforspeed;
    cin >> N >> K;
    memset(dp,inf,sizeof(dp));
    for(int i = 0;i < N;i++){
        cin >> M;
        for(int j = 0;j < M;j++){
            cin >> arr[i];
        }
        if(M == 1)
          DP[arr[0]][0] = 0;
        else{
          if(done()){
             DP[M][1] = 0;
          }else{
             DP[]
          }
        }
    }

    return 0;
}