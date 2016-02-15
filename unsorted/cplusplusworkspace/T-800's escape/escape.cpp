#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int R,C,K;
int tx,ty,ex,ey;
char g[50][50];
char v[50][50];

struct path{
    int d,k,x,y;
};
int bfs(){
    queue< path >q;
    q.push( (path){0,K,tx,ty});
    while(!q.empty()){
        int d = q.front().d;
        int k = q.front().k;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if(x < 0 || y < 0 || x > R-1 || y > C-1)continue;
        if(v[x][y])continue;
        v[x][y] = true;
        if(x == ex && y == ey)return d;
        if(g[x][y] == '#')continue;
        if(g[x][y] == 'R')k = K;
        if(k == 0)continue;
        q.push( (path){d+1,k-1,x+1,y});
        q.push( (path){d+1,k-1,x-1,y});
        q.push( (path){d+1,k-1,x,y+1});
        q.push( (path){d+1,k-1,x,y-1});
    }
    return -1;
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> C >> K;
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            cin >> g[i][j];
            if(g[i][j] == 'T'){
                tx = i;
                ty = j;
            }
            else if(g[i][j] == 'E'){
                ex = i;
                ey = j;
            }
        }
    }
    int ans = bfs();
    if(ans == -1) cout << "T-800 Terminated." << endl;
    else          cout << ans << endl;
    //fclose(stdin);
}
