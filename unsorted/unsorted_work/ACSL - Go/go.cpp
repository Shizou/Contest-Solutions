#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

string g[7];
bool v[7][7];
int mx = 0,temp = 0;

int f(int x,int y){
    if(x < 0 || y < 0 || x > 6 || y > 6)return 0;
    if(v[x][y])return 0;

    v[x][y] = 1;

    if(g[x][y] == '.')return 0;
    if(g[x][y] == 'X')return 0;
    if(g[x][y] == 'O')return 1;

    return f(x+1,y) + f(x-1,y) + f(x,y+1) + f(x,y-1);
}

int main(){
   // freopen("input.txt","r",stdin);
    for(int i = 0;i < 7;i++)getline(cin,g[i]);

    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            if(g[i][j] == 'X' || g[i][j] == 'O')continue;
            g[i][j] = 'X';

            if(i-1 >= 0){
                if(g[i-1][j] == 'O'){
                    temp = f(i-1,j);
                    if(temp > mx){
                        mx = temp;
                        cout << i << " " << j << " " << endl;
                    }
                }
            }
            if(i+1 < 7){
                if(g[i+1][j] == 'O'){
                    temp = f(i+1,j);
                    if(temp > mx){
                        mx = temp;
                        cout << i << " " << j << " " << endl;
                    }
                }
            }
            if(j-1 >= 0){
                if(g[i][j-1] == 'O'){
                    temp = f(i,j-1);
                    if(temp > mx){
                        mx = temp;
                        cout << i << " " << j << " " << endl;
                    }
                }
            }
            if(j+1 < 7){
                if(g[i][j+1] == 'O'){
                    temp = f(i,j+1);
                    if(temp > mx){
                        mx = temp;
                        cout << i << " " << j << " " << endl;
                    }
                }
            }
            g[i][j] = '.';
            memset(v,0,sizeof v);
        }
    }

    cout << mx << endl;
    //fclose(stdin);
    return 0;
}
