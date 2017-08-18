#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

char g[10][10];
bool v[10][10];
int x = 4,y = 3;

struct path{
    int r ,c ,dist;
};
void def(){
    g[0][9] = 'x';
    g[1][6] = 'x';
    g[2][2] = 'x';
    g[2][8] = 'x';
    g[3][0] = 'x';
    g[5][0] = 'x';
    g[5][1] = 'x';
    g[5][2] = 'x';
    g[5][3] = 'x';
    g[5][4] = 'x';
    g[5][5] = 'x';
    g[5][6] = 'x';
    g[6][7] = 'x';
    g[7][1] = 'x';
    g[8][3] = 'x';
    g[8][7] = 'x';
    g[9][9] = 'x';
}
int main(){
    memset(g,'.', sizeof g);
    memset(v,0,sizeof v);
    def();
    cin >> x >> y;
    x--;
    y--;
    g[y][x] = 'c';
    queue< path > Q;
    Q.push( (path){0,0,0});
    while(!Q.empty()){
        int r = Q.front().r;
        int c = Q.front().c;
        int d = Q.front().dist;
        Q.pop();
        if(r < 0 || c < 0 || r > 9 || c > 9)
            continue;
        if(g[r][c] == 'x')
            continue;
        if(v[r][c])
            continue;
        v[r][c] = 1;
        if(g[r][c] == 'c'){
            cout << "Betty will sweat " << d  << "mL to get to her candy cane"<< endl;
            break;

        }
        Q.push((path){r-1, c, d+1});
        Q.push((path){r+1, c, d+1});
        Q.push((path){r, c-1, d+1});
        Q.push((path){r, c+1, d+1});
    }

    return 0;
}
