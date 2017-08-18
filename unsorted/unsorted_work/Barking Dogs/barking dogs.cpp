#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
using namespace std;


const int MAXD = 1000;
int D,F,T,ans;
int wait[MAXD]; // wait time
int cnt[MAXD];  // time elapse
int doge[MAXD]; // # of barks
int state[MAXD];// -1 bark, 0 sleep, 1 wait
vector<int>adj[MAXD];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&D);
    memset(state,0,sizeof state);state[0] = -1;
    for(int i = 0;i < D;i++)
        scanf("%d",&wait[i]);
    for(int i = 0,a,b;i < F;i++){
        scanf("%d%d",&a,&b);a--,b--;
        adj[a].pb(b);
    }
    scanf("%d",&T);
    for(int t = 0;t <= T;t++){
        for(int d = 0;d < D;d++){
            if(state[d] == -1){
               cnt[d]++,doge[d]++;
               for(int i = 0;i < (int)adj[d].size();i++){
                    if(state[adj[d][i]] == 0){
                       state[adj[d][i]] = 1;
                       cnt[adj[d][i]] = -1;
                    }
               }
            }
            else if(state[d] ==  0){
                if(cnt[adj[]])
                cnt[d]++;
            }
            else if(state[d] ==  1){
                cnt[d]++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
