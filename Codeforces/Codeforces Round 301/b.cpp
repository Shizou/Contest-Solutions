#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) x.begin() x.end()
using namespace std;

const int MAXN = 999,MAXP = 1000,inf = 0x3f3f3f3f;

int n,k,p,x,y;
int sum;

bool dp[MAXP];

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> k >> p >> x >> y;
    for(int i = 0,m;i < k;i++){
        cin >> m;
        sum+=m;
    }
    for(int i = 0;i < MAXP;i++){
        for(int k = 0;k <= p;k++){
          if(dp[i-k])dp[i]=dp[i-k]+1;
        }
    }
    bool pos = false,idx = 0;
    for(int i = 0;i < MAXP;i++){
        if(dp[i] && (sum+i)/n <= x && (sum+i)/n >= y){
            pos = true;
            idx = i;
            break
        }
    }
    if(!pos)
        cout<< -1 << endl;
    else{
        while(true){
            for(int i = 0; i < p;i)
        }
    }
    return 0;
}