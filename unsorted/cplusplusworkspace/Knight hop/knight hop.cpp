#include<iostream>
#include<fstream>
#include<queue>
#include<string.h>
using namespace std;

char g[8][8];
bool v[8][8];
int x,y, x2,y2;
struct move{
    int r,c,m;
};
int main(){
    //freopen("input.txt","r",stdin);
    memset(g,'.',sizeof g);
    memset(v,0,sizeof v);

    cin >> x >> y >> x2 >> y2;
    x--;
    y--;
    x2--;
    y2--;
    g[x2][y2] = 'F';
    queue< move > Q;
    Q.push( (move){x,y,0});
    while(!Q.empty()){
        int r = Q.front().r;
        int c = Q.front().c;
        int m = Q.front().m;
        Q.pop();
        if(r < 0 || c < 0 || r > 7|| c > 7)
            continue;
        if(v[r][c])
            continue;
        if(g[r][c] == 'F'){
            cout << m << endl;
            break;
        }
        v[r][c] = 1;
        Q.push( (move){r-2,c-1,m+1});
        Q.push( (move){r-2,c+1,m+1});
        Q.push( (move){r+2,c-1,m+1});
        Q.push( (move){r+2,c+1,m+1});
        Q.push( (move){r-1,c+2,m+1});
        Q.push( (move){r+1,c+2,m+1});
        Q.push( (move){r-1,c-2,m+1});
        Q.push( (move){r+1,c+2,m+1});
    }
    //fclose(stdin);
    return 0;
}
