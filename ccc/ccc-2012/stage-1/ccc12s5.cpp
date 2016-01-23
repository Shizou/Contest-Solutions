#include<iostream>
#include<algorithm>
using namespace std;
int g[25][25];
bool m[25][25];
int row,col,t,r,c;
int main(){
    cin >> row >> col >> t;
    while(t--){cin >> r >> c; m[r-1][c-1] = 1;}
    for(int x = 0;x < row;x++){
        for(int y = 0;y < col;y++){
            if(x == 0 && y == 0)g[x][y]++;
            else if(m[x][y])continue;
            else if(y-1 >= 0 && x == 0 && !m[x][y-1])g[x][y] += g[x][y-1];
            else if(y-1 < 0 && x-1 >= 0 && !m[x-1][y]) g[x][y] += g[x-1][y];
            else if(x!=0 && y!= 0) {
                if(!m[x][y-1] && !m[x-1][y])
                    g[x][y] += g[x][y-1] + g[x-1][y];
                else if(!m[x][y-1])
                    g[x][y] += g[x][y-1];
                else if(!m[x-1][y])
                    g[x][y] += g[x-1][y];
            }
        }
    }
    cout << g[row-1][col-1] << endl;
}
