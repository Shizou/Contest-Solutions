#include<iostream>
#include<stdio.h>

using namespace std;

int N ,rgb[3], rg_b[3];
bool v[100][100],v2[100][100];
string g[100];

void b(int x, int y){
    if(x < 0 || y < 0 || x > N-1 || y > N-1)return;
    if(g[x][y] != 'B')return;
    if(v[x][y])return;
    v[x][y] = v2[x][y] = true;
    b(x+1,y);
    b(x,y+1);
    b(x-1,y);
    b(x,y-1);
}
void r_or_g(int x, int y,char c){
    if(x < 0 || y < 0 || x > N-1 || y > N-1)return;
    if(g[x][y] != c)return;
    if(v[x][y])return;
    v[x][y] = true;
    r_or_g(x+1,y,c);
    r_or_g(x,y+1,c);
    r_or_g(x-1,y,c);
    r_or_g(x,y-1,c);
}
void r_and_g(int x, int y){
    if(x < 0 || y < 0 || x > N-1 || y > N-1)return;
    if(g[x][y] == 'B')return;
    if(v2[x][y])return;
    v2[x][y] = true;
    r_and_g(x+1,y);
    r_and_g(x,y+1);
    r_and_g(x-1,y);
    r_and_g(x,y-1);
}

int main(){
    cin >> N;
    getline(cin,g[0]);
    for(int i = 0; i < N;i++)
        getline(cin,g[i]);

    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            if(g[i][j] == 'B'){
                if(!v[i][j]){
                    rgb[2]++;
                    rg_b[1]++;
                    b(i,j);
                }
            }
            else if(g[i][j] == 'R'){
                if(!v[i][j]){
                    rgb[0]++;
                    r_or_g(i, j, g[i][j]);
                }
                if(!v2[i][j]){
                    rg_b[0]++;
                    r_and_g(i, j);
                }
            }
            else if(g[i][j] == 'G'){
                if(!v[i][j]){
                    rgb[1]++;
                    r_or_g(i, j, g[i][j]);
                }
                if(!v2[i][j]){
                    rg_b[0]++;
                    r_and_g(i, j);
                }
            }
        }
    }
    printf("%d %d\n",rgb[0]+rgb[1]+rgb[2], rg_b[0]+rg_b[1]);
}

