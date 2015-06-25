#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) (x).begin(),(x).end()
#define f(x) (x)+300
#define x first
#define y second
using namespace std;

const int MAXN = 1000,inf = 0x3f3f3f3f,B = 0,W = 1;
int N,D;
int type[MAXN];
int dp[MAXN][MAXN];
vector<int>adj[MAXN];


int F(int x){
    return x+350;
}

int dfs(int n){
    int tree[2] = {0,0};// left subtree, right subtree
    int children = (int)adj[n].size();
    for(int i = 0;i < children;i++){
        tree[i] = dfs(adj[n][i]);
    }
    dp[n][F(tree[0]+tree[1]+type[n])] = 0;// the normal tree requires 0 prunes
    dp[n][F(0)] = 1;                      // pruning the entire subtree requires 1 prune
    if(children == 1){
        // dp[n][i+type[n]] = minimum of itself and the dp[child][i]
        // for example dp[0][-300+1] = min(dp[0][-300+1],dp[1][-300])
        // this is because -300+1 = 299
        for(int i = -300;i <= 300;i++)
            dp[n][F(i+type[n])] = min(dp[n][F(i+type[n])], dp[adj[n][0]][F(i)]);
    }
    else if(children == 2){
        // dp[n][i+type[n]] = min(itself, it's to children which add up to i)
        for(int i = -300;i <= 300;i++)
            for(int j = -300;j <= 300;j++)
               if(dp[adj[n][0]][F(i)] != inf && dp[adj[n][1]][F(j)] != inf)// if it's impossible for any branch to reach a sum (i or j)then it's impossible to make i+j
                  dp[n][F(i+j+type[n])] = min(dp[n][F(i+j+type[n])], dp[adj[n][0]][F(i)]+dp[adj[n][1]][F(j)]);
    }
    return tree[0]+tree[1]+type[n];// return the left subtree,right subtree, and itself
}

int main(){
    //freopen("Input/pruning9.in","r",stdin);
    scanf("%d%d",&N,&D);
    memset(dp,inf,sizeof(dp));
    for(int i = 0,id,cl,ch;i < N;i++){
        scanf("%d%d%d",&id,&cl,&ch);
        type[id] = (cl == W) ? 1:-1;
        for(int j = 0,nd;j < ch;j++){
            scanf("%d",&nd);
            adj[id].pb(nd);
        }
    }
    dfs(0);
    if(dp[0][F(D)] >= inf)
       printf("-1\n");
    else
       printf("%d\n",dp[0][F(D)]);

    return 0;
}

