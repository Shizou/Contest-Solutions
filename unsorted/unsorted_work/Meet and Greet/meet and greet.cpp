#include<iostream>
#include<stdio.h>
#include<vector>
#define abs(a) (a<0) ? -1*a:a
using namespace std;

int B,E,t,x,cnt;
char d;

vector<int>pos;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&B,&E);
    for(int i = 0;i < B;i++){
        scanf("%d %c",&t,&d);
        t*= (d == 'L') ? -1:1;
        x+= t;
        pos.push_back()
    }

    printf("%d\n",cnt);
}
