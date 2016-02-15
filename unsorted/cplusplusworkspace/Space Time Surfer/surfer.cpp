#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

char g[10][101][101];
bool v[10][101][101] = {0};
int R,C,T,M = -1;
int aR,aC;
string in;

struct state{
    int z,x,y,d;
};

int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> C >> T;
    getline(cin,in);
    for(int i = 0;i < T;i++){
        for(int j = 0;j < R;j++){
            getline(cin,in);
            for(int k = 0;k < C;k++){
                    g[i][j][k] = in[k];
                    if(in[k] == 'A'){
                        aR = j;
                        aC = k;
                    }
            }
        }
    }
    queue< state > q;
    q.push( (state){0,aR,aC,0});
    while(!q.empty()){
        int z = q.front().z;
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        if(x < 0 || y < 0 || z < 0 || x >= R || y >= C || z >= T) continue;

        if(v[z][x][y]) continue;
        v[z][x][y] = true;

        if(g[z][x][y] == 'X')continue;
        if(g[z][x][y] == 'B'){
            M = d;
            break;
        }

        q.push( (state){z,x+1,y,d+1});
        q.push( (state){z,x-1,y,d+1});
        q.push( (state){z,x,y+1,d+1});
        q.push( (state){z,x,y-1,d+1});

        for(int i = 0;i < T;i++){
            q.push( (state){i,x,y,d+1});
        }

    }
    cout << M << endl;
    //fclose(stdin);
}
