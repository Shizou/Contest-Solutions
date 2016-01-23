#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
#define LL long long
using namespace std;

const int MAXN = 400000;
int N;
int tree[MAXN][2];
int parent[MAXN];
bool v[MAXN];
vector<int>adj[MAXN];


void reset(){
    for(int i = 0;i < MAXN;i++){
        parent[i] = i;
        v[i] = false;
    }
}
pair<int,int> bfs(int u){
    queue< pair<int,int> >q;
    pair<int,int>fn = mp(0,0);
    q.push(mp(u,1));
    reset();
    v[u] = true;
    while(!q.empty()){
       int n = q.front().x;
       int d = q.front().y;
       q.pop();
       if(d > fn.y)
          fn.x = n,fn.y = d;
       for(int i = 0;i < (int)adj[n].size();i++){
          if(!v[adj[n][i]]){
             parent[adj[n][i]] = n;
             v[adj[n][i]]      = true;
             q.push(mp(adj[n][i],d+1));
           }
       }
    }
    return fn;
}
void dfs(int n){
      tree[n][0] = 1;
      tree[n][1] = 0;
      v[n] = true;
      for(int i = 0;i < (int)adj[n].size();i++){
          if(!v[adj[n][i]]){
            dfs(adj[n][i]);
            if(tree[adj[n][i]][1]  > tree[n][1]){
               tree[n][0] = tree[adj[n][i]][0];
               tree[n][1] = tree[adj[n][i]][1];
            }
            else if(tree[adj[n][i]][1] == tree[n][1])
               tree[n][0] += tree[adj[n][i]][0];
         }
      }
      tree[n][1] += 1;
}

int main(){
    freopen("Input/lhc.12-1.in","r",stdin);
    scanf("%d",&N);N--;
    int sn = 0;
    for(int i = 0,a,b;i < N;i++){
        scanf("%d%d",&a,&b);
        adj[--a].pb(--b);
        adj[b].pb(a);
        if(i == 0)sn = a;
    }
    // bfs from one node
    pair<int,int> ln1 = bfs(sn);
    // bfs from farthest node
    pair<int,int> ln2 = bfs(ln1.x);
    if(ln2.y%2 != 0){// the diameter of the tree is odd
       LL longest_path = ln2.y, occurences = 0;
       int back_track = ln2.y/2;
       while(back_track--){// backtrack to the central node
           ln2.x = parent[ln2.x];
       }
       // now dfs from the central node
       reset();
       dfs(ln2.x);
       LL best[2];
       best[0] = tree[ln2.x][0];
       best[1] = tree[ln2.x][1]-1;
       for(int i = 0;i < (int)adj[ln2.x].size();i++){
           if(tree[ adj[ln2.x][i] ][1] == best[1]){
              occurences+= tree[adj[ln2.x][i]][0]*(best[0]-tree[adj[ln2.x][i]][0]);
              best[0]-=tree[adj[ln2.x][i]][0];
           }
       }
       printf("%lld %lld\n",longest_path,occurences);

    }else{// the diamater of the tree is even
       LL longest_path = ln2.y, occurences = 0;
       int back_track = ln2.y/2;
       while(back_track--){// backtrack to the central node
           ln2.x = parent[ln2.x];
       }
       reset();
       dfs(ln2.x);// find the subtrees
       LL best[2][2]= { {0,0},{0,0}};
       for(int i = 0;i < (int)adj[ln2.x].size();i++){
           if(tree[adj[ln2.x][i]][1] > best[0][1]){ // there is only one subtree of maximal length
              best[0][1] = tree[adj[ln2.x][i]][1];
              best[0][0] = tree[adj[ln2.x][i]][0];
           }
           else if(tree[adj[ln2.x][i]][1] > best[1][1]){// there are other trees of smaller length
              best[1][1] = tree[adj[ln2.x][i]][1];
              best[1][0] = tree[adj[ln2.x][i]][0];
           }
           else if(tree[adj[ln2.x][i]][1] == best[1][1])// we add up the trees of the same length
              best[1][0] += tree[adj[ln2.x][i]][0];
       }
       occurences = best[0][0]*best[1][0];
       printf("%lld %lld\n",longest_path,occurences);
    }
    return 0;
}