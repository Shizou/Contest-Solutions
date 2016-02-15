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
    int size;
    int x = 0,y = 0;

    scanf("%d%d", &size, &x);

    for(int i = 1;i < size;i++){
        scanf("%d",&y);
        if(x%y == 0)
            printf("%d/1 \n",x/y);
        else if(x%y >= 1){
            printf("%d/%d\n", x/gcd(x,y),y/gcd(x,y));
        }
    }

    //fclose(stdin);

    return 0;
}

