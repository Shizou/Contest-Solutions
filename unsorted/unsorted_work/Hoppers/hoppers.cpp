#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int N,X,Y,P;
int sx,sy,ex,ey;
int a,b,c,d;
char g[16][16];

int main(){
    freopen("input.txt","r",stdin);
    memset(g,'.',sizeof g);
    scanf("%d",&N);
    scanf("%d%d",&X,&Y);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    scanf("%d",&P);
    for(int k = 0;k < P;k++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for(int i = a-1;i < c-1;i++)
            for(int j = b-1; j < d-1;j++)
                g[i][j] = '#';
    }


}
