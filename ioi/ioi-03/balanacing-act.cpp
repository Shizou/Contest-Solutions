#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define xx first
#define yy second
#define LL long long
using namespace std;

const int MAXN = 20000;
int N;
int dp[MAXN],mb[MAXN];
vector<int>adj[MAXN];


int dfs(int n,int p){
    for(int i = 0,cb = 0;i < (int)adj[n].size();i++){
        if(adj[n][i] != p){
            cb = dfs(adj[n][i],n);
            mb[n] = max(mb[n],cb);
            dp[n]+=cb;
        }
    }
    dp[n]++;// add the current node
    return dp[n];
}
int dfs2(int n,int p){
    if(n!=0){
        mb[n] = max(mb[n],dp[p]-dp[n]);
        dp[n] = dp[p];
    }
    for(int i = 0;i < (int)adj[n].size();i++)
        if(adj[n][i] != p)
            dfs2(adj[n][i],n);
}

int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 1,a,b;i < N;i++){
        cin >> a >> b;a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,0);
    dfs2(0,0);
    int n = 0, sb = 0x3f3f3f3f;
    for(int i = 0;i < N;i++){
        if(mb[i] < sb){
            n = i+1;
            sb = mb[i];
        }
    }
    cout << n << " " << sb << endl;
    return 0;
}

