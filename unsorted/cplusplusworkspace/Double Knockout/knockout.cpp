#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int n,a,b,c;
int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    printf("Round 0: %d undefeated, 0 one-loss, 0 eliminated\n",n);
    a = n;
    if(n%2 == 0){
        b = a/2;
        a/=2;
        printf("Round 1: %d undefeated, %d one-loss, %d eliminated\n",a,b,c);
    }
    else{
        b = a - a%2;
        a%=2;
        printf("Round 1: %d undefeated, %d one-loss, %d eliminated\n",a,b,c);
    }
    if(b%2 == 0){
        c = b - b%2;
        b%=2;
        printf("Round 2: %d undefeated, %d one-loss, %d eliminated\n",a,b,c);
    }
    fclose(stdin);
    return 0;
}
