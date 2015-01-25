#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct state{
    int r,c,lr,lc,d;
};
int G,R,C,s[2],e[2];
char g[1000][1000];
bool v[1000][1000];
int dist[2][1000][1000];
vector< pair<int,int> > mpatch;

int dp_bfs(int sr,int sc, int i){
    queue< pair<int, pair<int,int> > >q;
    q.push(make_pair(0,make_pair(sr,sc)));
    fill(&v[0][0],&v[0][0]+1000*1000,false);
    while(!q.empty()){
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(v[r][c] || d > dist[i][r][c])continue;
        dist[i][r][c] = d;
        v[r][c]=true;
        if(r != sr && c != sc && g[r][c] == 'M' || g[r][c] == 'W'){
            continue;
        }
        if(r+1 < R   && !v[r+1][c])q.push(make_pair(d+1,make_pair(r+1,c)));
        if(r-1 >= 0  && !v[r-1][c])q.push(make_pair(d+1,make_pair(r-1,c)));
        if(c+1 < C   && !v[r][c+1])q.push(make_pair(d+1,make_pair(r,c+1)));
        if(c-1 >= 0  && !v[r][c-1])q.push(make_pair(d+1,make_pair(r,c-1)));
    }
}
void bfs(int sr,int sc,int er,int ec){
    queue<state>q;
    q.push( (state){sr,sc,sr,sc,0} );
    fill(&v[0][0],&v[0][0]+1000*1000,false);
    while(!q.empty()){
        int r = q.front().r, c = q.front().c, d = q.front().d;
        int lr = q.front().lr, lc = q.front().lc;
        q.pop();
        if(r < 0 || c < 0 || r > R-1 || c > C-1 || v[r][c])continue;
        if(g[r][c] == 'W'|| g[r][c] == 'M'){v[r][c] = true;continue;}
        if(g[r][c] == 'U' || g[lr][lc] == 'U' )
            if(dist[0][lr][lc] <= dist[0][r][c] && dist[1][lr][lc] <= dist[1][r][c] )
                continue;
        if(r == er && c == ec){
            printf("pwned you in %d seconds eZ, learn to play n00b\n",d);
            return;
        }
        v[r][c] = true;
        q.push((state){r+1,c,r,c,d+1});
        q.push((state){r-1,c,r,c,d+1});
        q.push((state){r,c+1,r,c,d+1});
        q.push((state){r,c-1,r,c,d+1});
    }
     printf("terran so broken, apologize for playing this race\n");
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&G);
    while(G--){
        scanf("%d%d",&R,&C);
        mpatch.clear();
        for(int r = 0; r < R;++r){
            for(int c = 0; c < C;++c){
                scanf(" %c",&g[r][c]);
                dist[0][r][c] = dist[1][r][c] = 1<<26;
                if(g[r][c] == 'M')
                    mpatch.push_back(make_pair(r,c));
                else if(g[r][c] == 'P')
                    s[0] = r, s[1] = c;
                else if(g[r][c] == 'C')
                    e[0] = r, e[1] = c;
            }
        }
        dp_bfs(mpatch[0].first,mpatch[0].second,0);
        dp_bfs(mpatch[1].first,mpatch[1].second,1);
        bfs(s[0],s[1],e[0],e[1]);
    }
    return 0;
}
