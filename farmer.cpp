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

const int MAXQ = (int)1e6;
int Q,M,K;
int dp[MAXQ];
vector< pair<int,int> >item;// weight value


int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> Q >> M >> K;
    for(int i = 0,a;i < M;++i){
        cin >> a;
        item.pb(mp(a,a));
    }
    for(int i = 0,a;i < K;++i){
        cin >> a;
        item.pb(mp(a,a-1));
    }
    for(int i = 0;i < (int)item.size();++i){
        for(int j = Q-item[i].x;j >= 0;--j){
            dp[j+item[i].x] = max(dp[j+item[i].x],dp[j]+item[i].y);
        }
    }
    cout << dp[Q] << endl;
    return 0;
}

