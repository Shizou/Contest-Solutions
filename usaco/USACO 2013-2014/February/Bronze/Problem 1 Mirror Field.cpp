#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

enum dir{N,E,S,W};
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int R,C,max_l;
char g[1000][1000];

int explore(int r, int c, int d){
    int t = 0;
    while(r >= 0 && c >= 0  && r < R && c < C){
        if(g[r][c] == '\\'){
            switch(d){
                case N: d = W;break;
                case E: d = S;break;
                case W: d = N;break;
                case S: d = E;break;
            }
        }
        else{
            switch(d){
                case N: d = E;break;
                case E: d = N;break;
                case W: d = S;break;
                case S: d = W;break;
            }
        }
        r+=dr[d];
        c+=dc[d];
        t++;
    }
    return t;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> C;
    for(int i = 0; i < R;i++)
    for(int j = 0; j < C;j++)
        cin >> g[i][j];
    for(int i =0; i < R;i++){
        for(int j =0; j < C;j++){
            //corners
            if(i == 0 && j == 0){
                max_l = max(max_l, explore(i,j,S));
                max_l = max(max_l, explore(i,j,E));
            }
            else if(i == R-1 && j == 0){
                max_l = max(max_l, explore(i,j,N));
                max_l = max(max_l, explore(i,j,E));
            }
            else if(i == 0 && j == C-1){
                max_l = max(max_l, explore(i,j,S));
                max_l = max(max_l, explore(i,j,W));
            }
            else if(i == R-1 && j == C-1){
                max_l = max(max_l, explore(i,j,N));
                max_l = max(max_l, explore(i,j,W));
            }
            // edges
            else if(i == 0 && j != 0)
                max_l = max(max_l, explore(i,j,S));
            else if(i != 0 && j == 0)
                max_l = max(max_l, explore(i,j,E));
            else if(i == R-1 && j != 0)
                max_l = max(max_l, explore(i,j,N));
            else if(i != 0 && j == C-1)
                max_l = max(max_l, explore(i,j,W));
        }
    }
    printf("%d\n", (max_l != 0) ? max_l:-1);
    return 0;
}

