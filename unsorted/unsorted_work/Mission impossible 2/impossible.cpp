#include<iostream>
#include<stdio.h>

using namespace std;

int R,C,B;
string g[25];
bool v[20][20] = {0};

int r(int x, int y){
    if(x < 0 || y < 0 || x > R-1 || y > R-1)return 0;

    if(v[x][y])return 0;
    v[x][y] = 1;
    if(g[x][y] == '0')return 0;
    //g[x][y] = '0';


    return r(x+1,y) + r(x-1,y) +  r(x,y+1) +  r(x,y-1) + 1;
}

int main(){
   // freopen("input.txt","r",stdin);
    while(1){
        scanf("%d%d",&C,&R);
        getline(cin,g[0]);
        if(R == -1 && C == -1 )break;

        for(int i = 0; i < R;i++){
            getline(cin,g[i]);
        }
        B = 0;
        for(int i = 0;i < R;i++){
            for(int j = 0;j < C;j++){
                if(r(i,j))B++;
            }
        }
        cout << B << endl;
        for(int i = 0;i < R;i++)for(int j = 0;j < C;j++)v[i][j] = 0;
    }
    //fclose(stdin);
}
