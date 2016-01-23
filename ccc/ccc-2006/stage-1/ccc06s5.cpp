#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 5,MAXM = 4,MAXD = 1048576+5,INF = 0x3F3F3F3F;
int N,M,A,B,C,start;
int dp[MAXD];
int dr[] = {-1,-1,-1,0,1,1,1,0};
int dc[] = {-1,0,1,1,1,0,-1,-1};

char g[MAXM][MAXN];

int to_int_id(char grid [MAXM][MAXN]){
    int sum = 0;
    for(int i = 0,pwr = 0; i < M;++i)
        for(int j = 0; j < N;++j,++pwr)
            if(grid[i][j] == '1')
                sum+=1<<pwr;
    return sum;
}
int to_next_id(int n){
    char grid[MAXM][MAXN];
    int   cnt[MAXN][MAXN];
    int r = 0, c = 0;
    memset(grid,'0',sizeof(grid));
    memset(cnt,0,sizeof(cnt));
    while(n!=0){
        grid[r][c] = (n%2)+'0';
        c++;
        n/=2;
        if(c == N){
            c = 0;
            r++;
        }
    }
    for(r = 0;r < M;++r)
        for(c = 0;c < N;++c)
            for(int d = 0;d < 8;++d)
                if(r+dr[d] >= 0 && r+dr[d] < M && c+dc[d] >= 0 && c+dc[d] < N && grid[r+dr[d]][c+dc[d]] == '1')
                        cnt[r][c]++;

    for(r = 0;r < M;++r){
        for(c = 0;c < N;++c){
            if(grid[r][c] == '1'){
                if(cnt[r][c] < A)grid[r][c] = '0';
                if(cnt[r][c] > B)grid[r][c] = '0';
            }else{
                if(cnt[r][c] > C)grid[r][c] = '1';
            }
        }
    }
    return to_int_id(grid);
}

void update(int sn){
    queue< pair<int,int> >q;
    q.push(mp(sn,0));
    // cycle between possible edens then it's impossible
    if(to_next_id(to_next_id(sn)) == sn)
        return;
    dp[sn] = 0;
    while(!q.empty()){
        int n = q.front().first;
        int d = q.front().second;
        q.pop();
        if(d == 5)break;
        int next_node = to_next_id(n);
        if(dp[next_node] < d+1){
            dp[next_node] = d+1;
            q.push(mp(next_node,d+1));
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    fill(&dp[0],&dp[0]+MAXD,-1);
    scanf("%d%d%d%d%d",&M,&N,&A,&B,&C);
    for(int i = 0; i < M;i++){
        for(int j = 0; j < N;j++){
            scanf(" %c",&g[i][j]);
            g[i][j] = (g[i][j] == '*') ? '1':'0';
        }
    }
    start = to_int_id(g);
    int DD = 1<<(M*N);
    for(int i = 0; i <= DD;++i)
        if(dp[i] == -1)
            update(i);

    printf("%d\n",dp[start]);
    return 0;
}

