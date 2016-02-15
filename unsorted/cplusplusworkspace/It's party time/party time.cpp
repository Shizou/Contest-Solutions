#include<iostream>
#include<stdio.h>

using namespace std;

int N,a,b,c,d,d2;
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d%d%d",&a,&b,&c);
        d = a+c;
        while(a != d){
            a+=b;
            if(a > d)d+=c;
        }
        printf("%d\n",a);
    }
}
