#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>

using namespace std;


char f[243][243] = {'*'};
int N,B,T,L,R;

void r(int x, int y, int l){
    printf("X: %d Y: %d L: %d\n",x,y,l);
    printf("max: %.2f\n", (2*pow(3,l))/3);

    int dx = pow(3,l-1),dy = pow(3,l-1);
    cout << dx << " " << dy << endl;
    while(dx--){
        while(dy--){
            f[x+dx][y+dy] = ' ';
        }
        dy = pow(3,l-1);
    }
    if(l == 1)return;

    r( x/3, y/3, l-1);
    r( x/3, y+pow(3,l-2), l-1);
    r( x+pow(3,l-2),y/3,l-1);

    //r( x/3,6*y/3,l-1);
    //r( x+pow(2,l-1)-1, y/3, l-1);
    //r( x*2,y)
    //r()

    //r(x,y/3+1,l-1);


}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d%d%d",&N,&B,&T,&L,&R);
    memset(f,'*',sizeof f);

    r( pow(3,N+1)/3, pow(3,N+1)/3, N+1);

    for(int i = 0;i < pow(3,N+1);i++){
        for(int j = 0;j < pow(3,N+1);j++){
            cout << f[i][j];
        }
        cout << endl;
    }
    fclose(stdin);
    return 0;
}
