#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct state{
    int r,c,d;
    int rs,cs;
};

const int MAXD = 16;
int T,R,C,P,r1,c1,r2,c2;
int cr[] = {-1,0,1};
int cc[] = {-1,0,1};
bool grid[MAXD][MAXD];
bool v[MAXD][MAXD][10][10];// row col x-speed y-speed



int bfs(){
    queue<state>q;
    q.push((state){r1,c1,0,0,0});
    fill(&v[0][0][0][0],&v[0][0][0][0]+MAXD*MAXD*10*10,false);
    while(!q.empty()){
        int  r = q.front().r;
        int  c = q.front().c;
        int  d = q.front().d;
        int rs = q.front().rs;
        int cs = q.front().cs;
        q.pop();
        if(r == r2 && c == c2)
            return d;
        else{
            for(int i = 0; i < 3;i++){
                for(int j = 0; j < 3;j++){
                    rs+=cr[i],cs+=cc[j];
                    if(r+rs >= 0 && r+rs < R && c+cs >= 0 && c+cs < C && (rs < 4 && rs > -4) && (cs < 4 && cs > -4)){
                        if(!v[r+rs][c+cs][rs+3][cs+3] && !grid[r+rs][c+cs]){
                            v[r+rs][c+cs][rs+3][cs+3] = true;
                            q.push((state){r+rs,c+cs,d+1,rs,cs});
                        }
                    }
                    rs-=cr[i],cs-=cc[j];
                }
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&R,&C);
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        scanf("%d",&P);
        fill(&grid[0][0],&grid[0][0]+MAXD*MAXD,false);
        for(int i = 0,a,b,c,d; i < P;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            for(int j = a;j <= b;j++)
                for(int k = c;k <= d;k++)
                    grid[j][k] = true;
        }
        int ans = bfs();
        if(ans != -1)
            printf("Optimal solution takes %d hop(s).\n",ans);
        else
            printf("No solution.\n");
    }
    return 0;
}

