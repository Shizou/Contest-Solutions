#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;


int gcd(int x, int y){
    if(x == 0) return y;
    return gcd(y%x,x);
}

int main(){
    //freopen("input.txt","r",stdin);
    int whole = 0;
    int x = 0,y = 0;
    scanf("%d%d", &x, &y);

    if(x == 0 || y == 0)
        printf("0\n");
    else if(x%y == 0)
        printf("%d\n",x/y);
    else if(x%y >= 1){
        whole = x/y;
        x%=y;

        if(whole != 0)
            printf("%d %d/%d\n", whole, x/gcd(x,y),y/gcd(x,y));
        else
             printf("%d/%d\n", x/gcd(x,y),y/gcd(x,y));
    }
    return 0;
}
