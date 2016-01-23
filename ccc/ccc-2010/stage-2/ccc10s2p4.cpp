#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

const int MAXT = 10,MAXB = 10000;
int T,N,B,best;
int dp[MAXB][MAXT];
vector< pair<int,int> >adj[MAXT];// cost,value

int main(){
   //freopen("Input/purchase1.in","r",stdin);
   scanf("%d%d",&T,&N);
   memset(dp,0,sizeof(dp));
   for(int i = 0,c,v,t;i < N;++i){
       scanf("%d%d%d",&c,&v,&t);t--;
       adj[t].pb(mp(c,v));
   }
   scanf("%d",&B);
   for(int i = 0;i < (int)adj[0].size();i++)
       dp[adj[0][i].x][0] = max(dp[adj[0][i].x][0],adj[0][i].y);
   for(int t = 1;t < T;t++)
       for(int i = 0;i < (int)adj[t].size();i++)
           for(int j = 0;j <= B;j++)
               if(dp[j][t-1] != 0)
                  dp[j+adj[t][i].x][t] = max(dp[j+adj[t][i].x][t], dp[j][t-1]+adj[t][i].y);
   for(int i = 0;i <= B;i++)
       best = max(best,dp[i][T-1]);
   printf("%d\n",best == 0 ? -1:best);
   return 0;
}