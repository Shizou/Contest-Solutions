#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define Fill2D(a,b) fill(&(a)[0][0], &(a)[0][0]+sizeof(a)/sizeof((a)[0][0]), (b))
using namespace std;

struct path{
    int r,c,d;
};

int R,C,sr,sc;
int t[50][50];
vector< pair<int,int> > flood_points;
char g[50][50];
bool v[50][50];


int bfs(int rs, int cs){
    queue< path > q;
    q.push( (path){rs,cs,0});
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();
        if(r < 0 || c < 0 || r > R-1 || c > C-1)continue;
        if(v[r][c])continue;
        v[r][c] = true;
        if(g[r][c] == 'X' || g[r][c] == 'D'||t[r][c] <= d)continue;
        t[r][c] = d;
        q.push( (path){r+1,c,d+1});
        q.push( (path){r,c+1,d+1});
        q.push( (path){r-1,c,d+1});
        q.push( (path){r,c-1,d+1});
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&R,&C);
    for(int r = 0; r < R;++r){
        for(int c = 0;c < C;++c){
            scanf(" %c",&g[r][c]);
            if(g[r][c] == 'S'){
                sr = r;
                sc = c;
            }
            else if(g[r][c] == '*'){
                flood_points.push_back(make_pair(r,c));
            }
        }
    }
    Fill2D(t,1<<23);
    for(int i = 0; i < flood_points.size();++i){
        bfs(flood_points[i].first, flood_points[i].second);
        Fill2D(v,false);
    }
    int ans = -1;
    queue< path > q;
    q.push( (path){sr,sc,0});
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();
       /* printf("D:%d(%d,%d)\n",d,r,c);*/
        if(r < 0 || c < 0 || r > R-1 || c > C-1)continue;
        if(v[r][c])continue;
        v[r][c] = true;
        if(g[r][c] == 'X' || g[r][c] == '*'|| t[r][c] <= d)continue;
        if(g[r][c] == 'D'){
            ans = d;
            break;
        }
       /* printf("    D:%d(%d,%d)\n",d+1,r+1,c);
        printf("    D:%d(%d,%d)\n",d+1,r,c+1);
        printf("    D:%d(%d,%d)\n",d+1,r-1,c);
        printf("    D:%d(%d,%d)\n",d+1,r,c-1);*/
        q.push( (path){r+1,c,d+1});
        q.push( (path){r,c+1,d+1});
        q.push( (path){r-1,c,d+1});
        q.push( (path){r,c-1,d+1});
    }
    if(ans == -1)
        printf("KAKTUS\n");
    else
        printf("%d\n",ans);


    return 0;
}
