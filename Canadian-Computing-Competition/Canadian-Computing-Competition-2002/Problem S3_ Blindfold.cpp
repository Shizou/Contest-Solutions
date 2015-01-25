#include<iostream>
#include<cstdio>

using namespace std;

int R,C,M;
string g[375];
string cmd[30000];

int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> C;
    for(int i = 0; i < R;i++){
        cin >> g[i];
    }
    cin >> M;
    for(int i = 0; i < M;i++)
        cin >> cmd[i];
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            for(int k = 0; k < 4;k++){
                int dir = k;
                int r = i;
                int c = j;
                bool possible = true;
                // up 0, right 1, down = 2, left = 3
                for(int it = 0; it < M;it++){
                    if(r < 0 || c < 0 || r > R-1 || c > C-1 || g[r][c] == 'X'){
                        possible = false;
                        break;
                    }
                    if(cmd[it] == "F"){
                        r+= (dir == 0) ? -1: ((dir == 2) ? 1:0);
                        c+= (dir == 1) ? 1: ((dir == 3) ? -1:0);
                    }
                    else if(cmd[it] == "R"){
                        dir++;
                        dir%=4;
                    }
                    else if(cmd[it] == "L"){
                        dir--;
                        if(dir < 0)dir = 3;
                    }
                }
                if(r < 0 || c < 0 || r > R-1 || c > C-1 || g[r][c] == 'X')
                    possible = false;

                if(possible){
                   // cout << r << " " << c << endl;
                    g[r][c] = '*';

                }
            }
        }
    }
    for(int i = 0; i < R;i++)
        cout << g[i] << endl;
    return 0;
}
