// my idea, memorize the states with 4 long longs. So we split each long long into 4 sections of 2^15.
// for example lets say we want to represent a path of 1-2-3-4 what we'd do is store the first node
// visisted in the sections from 2^1-2^15, then for the second node visisted we'd store it in 2^16-2^31.
// Since a long long has at most 64 bits then we can store at best 4 nodes per long long. So for any paths
// longer than 4 then we store the next portion of it in the next long long. then we just memoize this.
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db 0
using namespace std;
typedef long long LL;


const int MAXN = 16,MOD = 13371337;
int T,N,cnt;
bool v[MAXN];
vector<int>adj[MAXN];
pair< pair<LL,LL>, pair<LL,LL> > path;
set< pair< pair<LL,LL>, pair<LL,LL> > >paths;// path

void rec(int n,int d){
     if(n == N-1){
        ++cnt;
        cnt%=MOD;
     }else{
        for(int i = 0;i < (int)adj[n].size();i++){
            pair< pair<LL,LL>, pair<LL,LL> > ppath = path;
            if(d >= 1  && d <= 4 )path.x.x |= (1 << (15*(d%5)+adj[n][i]));
            if(d >= 5  && d <= 8 )path.x.y |= (1 << (15*(d%5)+adj[n][i]));
            if(d >= 9  && d <= 12)path.y.x |= (1 << (15*(d%5)+adj[n][i]));
            if(d >= 13 && d <= 16)path.y.y |= (1 << (15*(d%5)+adj[n][i]));
            if(!v[adj[n][i]] && !paths.count(path)){
               v[adj[n][i]] = true;
               paths.insert(path);
               rec(adj[n][i],d+1);
               v[adj[n][i]] = false;
            }
            path = ppath;
        }
     }
}

int main(){
  freopen("input.txt","r",stdin);
  scanf("%d",&T);
  while(T--){
       scanf("%d",&N);
       memset(v,false,sizeof(v));
       paths.clear();
       for(int i = 0;i < MAXN;++i)
           adj[i].clear();
       for(int i = 0;i < N;++i){
           for(int j = 0,k;j < N;++j){
               scanf("%d",&k);
               if(k)adj[i].pb(j);
          }
       }
       cnt = 0;
       v[0] = true;
       path.x.x |= (1<<0);
       rec(0,1);
       printf("%d\n",cnt%MOD);
  }
}
