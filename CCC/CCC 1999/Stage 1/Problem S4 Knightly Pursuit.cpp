#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define mp make_pair
#define pb push_back
using namespace std;

const int MAXD = 500,INF = 0x3F3F3F3F;
int T,R,C,pr,pc,kr,kc;
int dp[MAXD][MAXD];
int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};

void bfs(){
    queue< pair<int,pair<int,int> > >q;
    q.push(mp(0,mp(kr,kc)));
    dp[kr][kc] = 0;
    while(!q.empty()){
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for(int i = 0; i < 8;i++){
            if(r+dr[i] >= 0 && r+dr[i] < R && c+dc[i] >= 0 && c+dc[i] < C){
                if(dp[r+dr[i]][c+dc[i]] > d+1){
                    dp[r+dr[i]][c+dc[i]] = d+1;
                    q.push(mp(d+1,mp(r+dr[i],c+dc[i])));
                }
            }
        }
    }

}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d",&R,&C,&pr,&pc,&kr,&kc);pr--,pc--,kr--,kc--;
        memset(dp,INF,sizeof(dp));
        bfs();
        for(int i = pr,d = 0;i < R;i++,d++){
            for(int k = 0; k < 2;k++){
                if(dp[i][pc]+2*k == d && i != R-1){
                    printf("Win in %d knight move(s).\n",dp[i][pc]+2*k);
                    goto end;
                }
            }
        }
        for(int i = pr,d = 0;i+1 < R;i++,d++){
            for(int k = 0; k < 20;k++){
                if(dp[i+1][pc]+2*k == d && i+1 != R-1){
                    printf("Stalemate in %d knight move(s).\n",dp[i+1][pc]+2*k);
                    goto end;
                }
            }
        }
        printf("Loss in %d knight move(s).\n",R-pr-2);
        end:;
    }
    return 0;
}
